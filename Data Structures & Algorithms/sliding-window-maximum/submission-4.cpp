class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int L = 0;
        priority_queue<pair<int,int>> maxHp;
        vector<int> result;

        for(int R = 0; R < nums.size(); R++){
            maxHp.push({nums[R], R});
            if(R >= k-1){
                while(maxHp.top().second <= R - k){
                    maxHp.pop();
                }
                result.push_back(maxHp.top().first);
            }
        }

        return result;
    }
};
