class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = 0, maxSum = INT_MIN;
        for(auto& num : nums){
            currSum = currSum < 0 ? num : currSum+num;
            maxSum = max(maxSum, currSum);
        }

        return maxSum;
    }
};
