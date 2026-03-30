class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {

        unordered_map<int,int> hm;

        for(int i = 0; i < numbers.size(); i++){
            int diff = target - numbers[i];

            if(hm.find(diff) != hm.end() && i > hm[diff]){
                return { hm[diff]+1, i+1 };
            }

            hm[numbers[i]] = i;
        }

        return {};
    }
};
