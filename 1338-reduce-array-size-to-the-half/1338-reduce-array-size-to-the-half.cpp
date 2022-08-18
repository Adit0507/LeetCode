class Solution {
public:
    int minSetSize(vector<int>& arr) {
        // Store freq of all elements
        // Copy all frequencies into array
        // Sort in descending order
        // Delete until array is half
        unordered_map <int, int> map;
        int n = arr.size();
        
        for(auto a: arr){
            map[a]++;
        }
        vector <int> freq;
        // store in array from map
        for(auto m: map){
            freq.push_back(m.second);
        }
        
        //sorting in descedning order
        sort(freq.begin(), freq.end(), greater<int> ());
        int sum = 0, ans =0;
        for(auto i: freq){
            if(sum < n/2){
                ans ++;
                sum += i;
            } 
            else
                break;
        }
        return ans;
    }
};