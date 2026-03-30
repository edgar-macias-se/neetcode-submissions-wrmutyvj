class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> hm;

        for(int i=0; i <= nums.size(); i++){
            int rest = target - nums[i];
            
            if(hm.find(rest) != hm.end()){
                 return {hm[rest], i};
            }

            hm[nums[i]] = i;

        }
        return {};
    }
};
