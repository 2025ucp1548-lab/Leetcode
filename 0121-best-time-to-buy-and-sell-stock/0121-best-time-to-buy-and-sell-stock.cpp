class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int n=prices.size();
       int minimum=prices[0];
       int max_profit=0;
       for(int i=1;i<n;i++)
       {
        int current=prices[i]-minimum;
        max_profit=max(max_profit,current);
        minimum=min(minimum,prices[i]);
       }
       return max_profit;
    }
};