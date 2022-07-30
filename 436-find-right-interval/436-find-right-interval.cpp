class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector <int> ans(intervals.size());
        map <int, int> m;
        for(int i=0; i < intervals.size(); i++)
            m[intervals[i][0]] = i;
        for(int i = 0; i < intervals.size(); i++)
            // lower_bound is used to return an iterator pointing to the first element in range [first, last] whihc has a value not less than val
            ans[i] = m.lower_bound(intervals[i][1]) != end(m) ? m.lower_bound(intervals[i][1])->second : -1;
        return ans;
    }
};