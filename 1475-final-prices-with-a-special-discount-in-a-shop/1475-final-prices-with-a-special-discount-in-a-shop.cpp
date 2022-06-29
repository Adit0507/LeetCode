class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> s;
        s.push(0);
        
        for(int i=1; i < prices.size(); i++){
            while(!s.empty() && prices[s.top()] >= prices[i])
                prices[s.top()] -= prices[i], s.pop();
            s.push(i);
        }
        return prices;
    }
};