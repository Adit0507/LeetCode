class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        int ans = 0;
        long range = startFuel;

        int i = 0;
        priority_queue <long> pq;
        while(i < stations.size()){
            if(range >= target)        // Ability to reach the target
                return ans;
            if(range < stations[i][0]){     // We refuel, but stay on the same index of the pump, we need to make sure that, we reacjhed till its position
                if(pq.empty())
                    return -1;
                range += pq.top();
                pq.pop();
                ans ++;
                continue;
            }
            else                // We can pass this pump, no refuel needed 
                pq.push(stations[i][1]);
            i++;
        }
        while(range < target && !pq.empty()){   // Check if we can reach the target or not
            range += pq.top();
            pq.pop();
            ans ++;
        }
        return range >=target ? ans : -1;
    }
};