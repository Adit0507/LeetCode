class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector <int> occur(26);
        for(int i=0; i < words2.size(); i++){
            vector <int> temp(26);
            for(int j =0; j < words2[i].size(); j++){
                temp[words2[i][j] - 'a'] ++;
                occur[words2[i][j] - 'a'] = max(occur[words2[i][j] - 'a'], temp[words2[i][j] - 'a']);
            }
        }
        
        for(int i =0; i< words1.size(); i++){
            vector<int> temp = occur;
            for(int j=0; j < words1[i].size(); j++){
                temp[words1[i][j] - 'a']--;
            }
            
            bool subset = true;
            for(int j=0; j < 26; j++){
                if(temp[j] > 0){
                    subset = false;
                }
            }
            
            if(subset){
                ans.push_back(words1[i]);
            }
        }
        return ans;
    }
};














