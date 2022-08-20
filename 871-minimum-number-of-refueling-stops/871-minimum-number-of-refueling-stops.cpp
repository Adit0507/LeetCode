class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int ans = 0;
        long range = startFuel;

        int i = 0;
        priority_queue <long> pq;
        while(i < stations.size()){
            if(range >= target)
                return ans;
            if(range < stations[i][0]){
                if(pq.empty())
                    return -1;
                range += pq.top();
                pq.pop();
                ans ++;
                continue;
            }
            else
                pq.push(stations[i][1]);
            i++;
        }
        while(range < target && !pq.empty()){
            range += pq.top();
            pq.pop();
            ans ++;
        }
        return range >=target ? ans : -1;
    }
};