Design an algorithm to encode **a list of strings** to **a string**. The **encoded string** is then sent over the network and is **decoded** back to the **original list** of strings.

Implement two methods:
* `encode(strs)`: Serializes a list of strings into a single string.
* `decode(s)`: Deserializes the encoded string back into the original list of strings.

Machine 1 encodes the list into a string, and Machine 2 decodes that string. The decoded list on Machine 2 must be identical to the original input `strs` on Machine 1.

**Example 1:**

```
Input: strs = ["Hello","World"]

Output: ["Hello","World"]
```

**Explanation:**
```
encoded_string = encode(strs)
// Machine 1 ---encoded_string---> Machine 2
decoded_strs = decode(encoded_string)
```


**Example 2:**
```
Input: strs = [""]

Output: [""]
```


**Constraints:**
* `0 <= strs.length < 100`
* `0 <= strs[i].length < 200`
* `strs[i]` contains any possible characters out of `256` valid ASCII characters.


**Follow up:** Could you write a generalized algorithm to work on any possible set of characters?


