class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX, profit = 0;

        for(int &price : prices){
            if(price < buy) {
                buy = price;
            }

            if(profit < price - buy) {
                profit = price - buy;
            }
        }

        return profit;        
    }
};
