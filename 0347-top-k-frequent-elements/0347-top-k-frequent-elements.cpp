class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> c;
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
        
        for(auto i: nums){
            c[i]++;
        }
        
        for(auto &i: c){
            pq.push({i.second, i.first});
            if(pq.size() >k)
                pq.pop();
        }
        
        vector<int> ans;
        while(k --){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};