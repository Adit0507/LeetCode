class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n= tasks.size();
        unordered_map<int, int>mp;   
        // Storing freqs.
        for(int i= 0; i< n; i++){
            mp[tasks[i]]++;
        }
        int ans = 0;
        
        for(auto x:mp){
            int freq= x.second;
            // We cant complete it if the freq is 1
            if(freq== 1) return -1;
            else if(freq%3 ==0) ans += freq/3;
            else if(freq%3 == 1|| freq%3== 2)
                ans += freq/3 +1;
        }
        
        return ans;
    }
};