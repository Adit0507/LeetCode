class Solution {
public:
    void part(int i, string s, vector<string> &path, vector<vector<string>> &ans){
        if(i== s.size()){
            ans.push_back(path);
            return;
        }
        
        for(int j = i; j < s.size(); j++){
            if(isPalindrome(s, i, j)){
                path.push_back(s.substr(i, j - i + 1));
                part(j + 1, s, path, ans);
                path.pop_back();
            }
        }
    }
    
    bool isPalindrome(string s, int start, int end){
        while(start <=end)
            if(s[start ++] !=s[end--])
                return false;
        return true;
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        part(0, s, path, ans);
        
        return ans;
    }
};