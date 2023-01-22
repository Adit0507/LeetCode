class Solution {
public:
    int minCut(string s) {
        int n= s.size();
        if(n <=1) return 0;
        
        int i, j, cut[n +1];
        for(int i= 0; i <= n; i++)
            cut[i] = i -1;
        
        for(i= 1; i <n; i++){
            for(j =0; (i -j) >= 0 && (i +j)< n && s[i-j] ==s[i +j]; j++)
                cut[i +j +1] = min(cut[i +j +1], 1 + cut[i -j]);
            
            for(j =0; (i -j-1) >= 0 && (i +j)< n && s[i-j-1] ==s[i +j]; j++)
                cut[i +j +1] = min(cut[i +j +1], 1 + cut[i -j-1]);
        }
        return cut[n];
    }
};