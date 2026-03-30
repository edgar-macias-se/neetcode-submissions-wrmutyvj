func combine(n int, k int) [][]int {
	combs := [][]int{}
	
	var helper func(i int, currCombs []int)

	helper = func(i int, currCombs []int){
		if len(currCombs) == k {
			tmp := make([]int, k)
			copy(tmp, currCombs)
			combs = append(combs, tmp)
			return
		}

		for h := i; h <= n; h++  {
			currCombs = append(currCombs, h)
			helper(h+1, currCombs)
			currCombs = currCombs[:len(currCombs)-1]
		}
	}

	helper(1, []int{})
	return combs
}


