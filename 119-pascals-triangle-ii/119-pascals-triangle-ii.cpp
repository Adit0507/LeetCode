class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev={1},curr;
    for(int i=1;i<=rowIndex;i++)
    {
        curr.clear();
        curr.resize(i+1,1);
        for(int j=1;j<i;j++)
            curr[j]=prev[j]+prev[j-1];
        prev=curr;
    }
    return prev;
    }
};