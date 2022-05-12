class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxCount = 0;
        int ans = 0;
        int n = s.size();
        
        vector<int> c(26);
        
        int j = 0;
        for(int i = 0; i < n; i++){
            c[s[i] - 'A']++;
            maxCount = max(maxCount, c[s[i] - 'A']);
            while(j <= i && i - j + 1 - maxCount > k){
                --c[s[j] - 'A'];
                j++;
            }
            ans = max(ans, i - j+1);
        }
        return ans;
    }
};