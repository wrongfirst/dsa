func groupAnagrams(strs []string) [][]string {
	ans := make(map[[26]int][]string)
	for _, s := range strs {
		count := [26]int{}
		for _, c := range s {
			count[c-'a']++
		}
		ans[count] = append(ans[count], s)
	}
	
	result := make([][]string, 0, len(ans))
	for _, group := range ans {
		result = append(result, group)
	}
	return result
}
