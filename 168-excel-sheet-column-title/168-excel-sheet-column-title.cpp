class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        
        while(columnNumber){
            ans.insert(ans.begin(), 'A' + (columnNumber - 1)%26);
            columnNumber = (columnNumber - 1)/26;
        }
        return ans;
    }
};