class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int globMax = nums[0], globMin = nums[0];
        int curMax = 0, curMin=0, total = 0;

        for(auto& num : nums){
            curMax = max(curMax+num, num);
            globMax = max(globMax, curMax);
            curMin = min(curMin + num, num);
            globMin = min(globMin, curMin);
            total += num;
        }

        return globMax > 0 ? max(globMax, total - globMin) : globMax;
    }
};