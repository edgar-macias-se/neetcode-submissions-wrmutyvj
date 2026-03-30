class Solution {
    /**
     * @param {number[]} nums
     * @param {number} k
     * @return {number[]}
     */
    maxSlidingWindow(nums, k) {
        let result = [];
        for(let right=0; right <= nums.length - k; right++){
            result.push(Math.max(...nums.slice(right, right+k)));
        }

        return result;
    }
}
