func subsets(nums []int) [][]int {
    var (
        subsets [][]int = [][]int{}
        currSet []int = []int{}
    )

    helper(0, nums, currSet, &subsets)

    return subsets
}

func helper(i int, nums, currSet []int, subsets *[][]int){
    if i >= len(nums) {
        tmp := make([]int, len(currSet))
        copy(tmp,currSet)
        *subsets = append(*subsets, tmp)
        return
    }

    currSet = append(currSet, nums[i])
    helper(i+1, nums, currSet, subsets)
    currSet = currSet[:len(currSet)-1]
    helper(i+1, nums, currSet, subsets)
}