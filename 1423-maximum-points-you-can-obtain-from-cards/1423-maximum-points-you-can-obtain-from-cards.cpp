class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        vector <int> pre1(cardPoints.begin(), cardPoints.end());
        vector <int> pre2(cardPoints.begin(), cardPoints.end());
        int ret = 0;
        int n = cardPoints.size();
        for(int i = 1; i < n; i++){
            pre1[i] += pre1[i - 1];
        }
        for(int i = n - 2; i >= 0; i--){
            pre2[i] += pre2[i + 1];
        }
        if(k >= n){
            return pre1[n-1];
        } 
        int i = k - 1;
        ret = pre1[i];
        i --;
        int j = n - 1;
        while(i >= 0){
            ret = max(ret, pre1[i] + pre2[j]);
            i --;
            j --;
        }
        ret = max(ret, pre2[n - k]);
        return ret;
    }
};