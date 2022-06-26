class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total = 0;
        
        for (int i=0; i < k; i++)
            total += cardPoints[i];
        
        int best = total;
        for(int i = k -1, j = cardPoints.size() - 1; ~i; i--, j--)
            total += cardPoints[j] - cardPoints[i], best = max(best, total);
       return best;
    }
};