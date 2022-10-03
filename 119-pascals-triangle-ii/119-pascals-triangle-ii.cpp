class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> p(rowIndex +1, 0);
        p[0] = 1;
        for(int i =0; i < rowIndex + 1; i++){
            for(int j= i; j >= 1; j--)
                p[j] += p[j -1];
        }
        return p;
    }
};