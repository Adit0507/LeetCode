class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l, r;
        unordered_map<int, int> s;
            
        for(l= 0, r= 0; r < fruits.size(); ++r){
            s[fruits[r]] ++;
            
            if(s.size() > 2){
                if(--s[fruits[l]] == 0)
                    s.erase(fruits[l]);
                l++;
            }
        }
        
        return r - l;
    }
};