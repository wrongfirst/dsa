
def encode(strs: list[str]) -> str:
    res: list[str] = []
    for s in strs:
        res.append(str(len(s)))
        res.append("#")
        res.append(s)
    return "".join(res)

def decode(s: str) -> list[str]:
    res: list[str] = []
    i = 0
    
    while i < len(s):
        j = i
        while s[j] != '#':
            j += 1
        length = int(s[i:j])
        i = j + 1
        j = i + length
        res.append(s[i:j])
        i = j
        
    return res
