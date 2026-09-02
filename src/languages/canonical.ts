export type CanonicalInputType =
  | 'standard'
  | 'tree'
  | 'tree_node'
  | 'linked_list'
  | 'linked_list_array'
  | 'linked_list_cycle'
  | 'graph'
  | 'interval'
  | 'interval_array'
  | 'byte_grid';

export type CanonicalReturnType =
  | 'standard'
  | 'tree'
  | 'tree_node'
  | 'linked_list'
  | 'graph'
  | 'void';

export type CanonicalMode =
  | 'function'
  | 'operations'
  | 'compose';

/**
 * Root JSON structure of a canonical-data.json file
 */
export interface CanonicalData {
  exercise: string;
  property?: string;
  comments?: string[];
  comparison?: 'exact' | 'unordered' | 'unordered_nested';
  returns?: CanonicalReturnType;
  inputs?: Record<string, CanonicalInputType>;
  mutation?: { target: string };
  mode?: CanonicalMode;
  compose?: [string, string];
  receiver?: string;
  cases: CanonicalCase[];
}

/**
 * A canonical case item is either a leaf test case or a group containing nested cases.
 */
export type CanonicalCase = CanonicalTestCase | CanonicalCaseGroup;

/**
 * A group of test cases with a descriptive grouping label.
 */
export interface CanonicalCaseGroup {
  description: string;
  cases: CanonicalCase[];
}

/**
 * Leaf test case representing a single test invocation.
 */
export interface CanonicalTestCase {
  uuid?: string;
  description: string;
  property: string;
  input: Record<string, any>;
  expected: any;
  comments?: string[];
  comparison?: 'exact' | 'unordered' | 'unordered_nested';
  returns?: 'tree' | 'linked_list' | 'graph' | 'void' | 'standard';
  inputs?: Record<string, CanonicalInputType>;
  mutation?: { target: string };
}

/**
 * Flattened test case preserving optional parent group description context.
 */
export interface FlatCanonicalTestCase extends CanonicalTestCase {
  groupDescription?: string;
}

/**
 * Type guard to distinguish leaf CanonicalTestCase from CanonicalCaseGroup.
 */
export function isTestCase(c: CanonicalCase): c is CanonicalTestCase {
  return ('property' in c || 'expected' in c) && 'input' in c;
}

/**
 * Recursively flattens nested case groups into a flat array of test cases.
 */
export function flattenCases(
  cases: CanonicalCase[],
  groupDesc?: string
): FlatCanonicalTestCase[] {
  const result: FlatCanonicalTestCase[] = [];

  for (const c of cases) {
    if (isTestCase(c)) {
      result.push({
        ...c,
        property: (c as any).property || '',
        ...(groupDesc ? { groupDescription: groupDesc } : {})
      });
    } else if (Array.isArray(c.cases)) {
      const nestedGroup = groupDesc
        ? `${groupDesc} - ${c.description}`
        : c.description;
      result.push(...flattenCases(c.cases, nestedGroup));
    }
  }

  return result;
}

/**
 * Universal structured type descriptor for canonical parameters and return values.
 */
export type CanonicalTypeDescriptor =
  | { kind: 'primitive'; type: 'int' | 'uint32' | 'float' | 'bool' | 'string' }
  | { kind: 'array'; element: CanonicalTypeDescriptor }
  | { kind: 'tree' }
  | { kind: 'tree_node' }
  | { kind: 'linked_list' }
  | { kind: 'linked_list_array' }
  | { kind: 'linked_list_cycle' }
  | { kind: 'graph' }
  | { kind: 'interval' }
  | { kind: 'interval_array' }
  | { kind: 'byte_grid' }
  | { kind: 'void' }
  | { kind: 'unknown' };

export interface CanonicalParamDescriptor {
  name: string;
  type: CanonicalTypeDescriptor;
  isMutationTarget: boolean;
}

export interface CanonicalMethodDescriptor {
  name: string;
  parameters: CanonicalParamDescriptor[];
  returnType: CanonicalTypeDescriptor;
}

export interface CanonicalSignature {
  exercise: string;
  mode: CanonicalMode;
  name: string; // Function name or class name
  receiver?: string;
  compose?: [string, string];
  mutationTarget?: string;
  parameters: CanonicalParamDescriptor[];
  returnType: CanonicalTypeDescriptor;
  methods: CanonicalMethodDescriptor[]; // For operations mode
}

/**
 * Infer a structured CanonicalTypeDescriptor from sample data and optional semantic hint.
 */
export function inferCanonicalType(
  val: any,
  hint?: CanonicalInputType | CanonicalReturnType,
  allCases?: FlatCanonicalTestCase[],
  key?: string
): CanonicalTypeDescriptor {
  if (hint === 'tree') return { kind: 'tree' };
  if (hint === 'tree_node') return { kind: 'tree_node' };
  if (hint === 'linked_list') return { kind: 'linked_list' };
  if (hint === 'linked_list_array') return { kind: 'linked_list_array' };
  if (hint === 'linked_list_cycle') return { kind: 'linked_list_cycle' };
  if (hint === 'graph') return { kind: 'graph' };
  if (hint === 'interval') return { kind: 'interval' };
  if (hint === 'interval_array') return { kind: 'interval_array' };
  if (hint === 'byte_grid') return { kind: 'byte_grid' };
  if (hint === 'void') return { kind: 'void' };

  if (val === null || val === undefined) {
    return { kind: 'unknown' };
  }

  if (typeof val === 'boolean') {
    return { kind: 'primitive', type: 'bool' };
  }

  if (typeof val === 'number') {
    if (Number.isInteger(val)) {
      return val > 2147483647 || val < -2147483648
        ? { kind: 'primitive', type: 'uint32' }
        : { kind: 'primitive', type: 'int' };
    }
    return { kind: 'primitive', type: 'float' };
  }

  if (typeof val === 'string') {
    return { kind: 'primitive', type: 'string' };
  }

  if (Array.isArray(val)) {
    if (val.length === 0) {
      // Look across all other cases to find an example with elements
      if (allCases && key) {
        for (const c of allCases) {
          const sample = c.input?.[key];
          if (Array.isArray(sample) && sample.length > 0) {
            return { kind: 'array', element: inferCanonicalType(sample[0]) };
          }
        }
      }
      return { kind: 'array', element: { kind: 'primitive', type: 'int' } };
    }
    return { kind: 'array', element: inferCanonicalType(val[0]) };
  }

  return { kind: 'unknown' };
}

/**
 * Parse a CanonicalData object into a normalized, language-agnostic signature representation.
 */
export function parseCanonicalSignature(meta: CanonicalData): CanonicalSignature {
  const flat = flattenCases(meta.cases);
  const first = flat[0];
  const mode: CanonicalMode = meta.mode || (first?.property === 'operations' ? 'operations' : 'function');
  const exercise = meta.exercise;
  const inputsMeta = meta.inputs || first?.inputs || {};
  const returnsMeta = meta.returns || first?.returns || 'standard';
  const mutationTarget = meta.mutation?.target || first?.mutation?.target;

  if (mode === 'operations') {
    const ops: string[] = first?.input?.operations || [];
    const args: any[][] = first?.input?.arguments || [];
    const exps: any[] = first?.expected || [];
    const className = ops[0] || 'Solution';

    const ctorParams: CanonicalParamDescriptor[] = (args[0] || []).map((arg, idx) => ({
      name: `arg${idx + 1}`,
      type: inferCanonicalType(arg),
      isMutationTarget: false
    }));

    const methodMap = new Map<string, CanonicalMethodDescriptor>();
    for (let i = 1; i < ops.length; i++) {
      const op = ops[i];
      if (!methodMap.has(op)) {
        const methodArgs = args[i] || [];
        const expectedVal = exps[i];
        const returnType = expectedVal === null || expectedVal === undefined
          ? { kind: 'void' as const }
          : inferCanonicalType(expectedVal);

        methodMap.set(op, {
          name: op,
          parameters: methodArgs.map((a, aIdx) => ({
            name: `arg${aIdx + 1}`,
            type: inferCanonicalType(a),
            isMutationTarget: false
          })),
          returnType
        });
      }
    }

    return {
      exercise,
      mode: 'operations',
      name: className,
      receiver: className,
      mutationTarget,
      parameters: ctorParams,
      returnType: { kind: 'void' },
      methods: Array.from(methodMap.values())
    };
  }

  if (mode === 'compose') {
    const compose = meta.compose || ['decode', 'encode'];
    const outerFn = compose[0];
    const innerFn = compose[1];
    const inputKeys = Object.keys(first?.input || {});

    const params: CanonicalParamDescriptor[] = inputKeys.map((k) => ({
      name: k,
      type: inferCanonicalType(first.input[k], inputsMeta[k], flat, k),
      isMutationTarget: false
    }));

    const retType = inferCanonicalType(first?.expected, returnsMeta === 'standard' ? undefined : returnsMeta);

    return {
      exercise,
      mode: 'compose',
      name: outerFn,
      receiver: meta.receiver,
      compose: [outerFn, innerFn],
      mutationTarget,
      parameters: params,
      returnType: retType,
      methods: []
    };
  }

  // Standard function mode
  const propName = first?.property || meta.property || exercise;
  const inputKeys = Object.keys(first?.input || {});

  const params: CanonicalParamDescriptor[] = inputKeys.map((k) => ({
    name: k,
    type: inferCanonicalType(first.input[k], inputsMeta[k], flat, k),
    isMutationTarget: k === mutationTarget
  }));

  const retType = mutationTarget
    ? { kind: 'void' as const }
    : inferCanonicalType(first?.expected, returnsMeta === 'standard' ? undefined : returnsMeta);

  return {
    exercise,
    mode: 'function',
    name: propName,
    mutationTarget,
    parameters: params,
    returnType: retType,
    methods: []
  };
}
