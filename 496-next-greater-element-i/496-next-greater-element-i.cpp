class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack <int> s;
        map <int, int> m;
        vector <int> ans;
        
        for (int i =0; i < nums2.size(); i++){
            while (!s.empty()){
                if (s.top() < nums2[i]){
                    m.insert(pair<int,int>(s.top(),nums2[i]));
                    s.pop();
                }
                else 
                    break;
            }
            s.push (nums2[i]);
        }
        
        for (int i = 0; i < nums1.size(); i++){
            int val = m[nums1[i]];
            
            if(val == 0) ans.push_back(-1);
            else ans.push_back(val);
        }        
        
        return ans;
    }
};







