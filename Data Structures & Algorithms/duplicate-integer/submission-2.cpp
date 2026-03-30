class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for(int el : nums){
            if(seen.count(el)){
                return true;
            }
            seen.insert(el);
        } 

        return false;
    }
};