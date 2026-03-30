class Solution {
    /**
     * @param {number} target
     * @param {number[]} nums
     * @return {number}
     */
    minSubArrayLen(target, nums) {
        let left=0, total=0, minLength=Infinity;
        for(let r=0; r < nums.length; r++){
            total += nums[r];
            while(total >= target){
             total -= nums[left];
             minLength = Math.min(minLength, r - left + 1);
             left++;
            }
        }

        return minLength == Infinity ? 0 : minLength;
    }
}
