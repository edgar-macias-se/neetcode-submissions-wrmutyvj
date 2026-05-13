class Solution {
    vector<vector<int>> subsets;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> curr;
        backtrack(0, curr, nums);
        return subsets;
    }

private:
    void backtrack(int start, vector<int>& curr, vector<int>& nums) {
        subsets.push_back(curr);
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i-1]) continue;
            curr.push_back(nums[i]);
            backtrack(i + 1, curr, nums);
            curr.pop_back();
        }
    }
};