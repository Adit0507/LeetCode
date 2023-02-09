class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long c = 0;
        vector<unordered_set<string>> a(26);
        int n= ideas.size();

        for(string i: ideas)
            a[i[0]- 'a'].insert(i.substr(1));
        
        for(int i= 0; i < 25; i++){
            for(int j= i + 1; j < 26; j++){
                unordered_set<string> s;
                s.insert(a[i].begin(), a[i].end());
                s.insert(a[j].begin(), a[j].end());
                c += (a[i].size()- s.size())*(a[j].size()- s.size());
            }
        }
        
        return c*2;
    }
};