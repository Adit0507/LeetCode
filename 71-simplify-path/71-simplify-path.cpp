class Solution {
public:
    string simplifyPath(string path) {
        vector<string> v;
        
        for(int i = 0; i < path.length();){
            if(path[i] != '/'){
                string dir="";
                
                while (i < path.length() && path[i] != '/')
                    dir += path[i++];
                
                if(dir == ".."){
                    if(v.size())
                        v.pop_back();
                }
                else if(dir != ".") {
                    v.push_back(dir);
                }
            }
            else
                i++;
        }
        string ans= "";
        
        for(string x: v)
            ans += "/" + x;
        
        return !ans.length() ? "/" : ans;
    }
};