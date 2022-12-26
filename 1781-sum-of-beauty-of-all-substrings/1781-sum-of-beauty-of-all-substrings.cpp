class Solution {
public:
    int beautySum(string s) {
        int n= s.length();
        int ans= 0;
        
        for(int i = 0; i < n; i++){
            unordered_map<char, int> m;
            for(int j =i; j <n; j++){
                m[s[j]]++;
                int mx= -1, mn= 501;
                for(auto[key, val]: m){
                    mx= max(mx, val);
                    mn= min(mn,val);
                }
                ans += mx- mn;
            }
        }
        return ans;
    }
};