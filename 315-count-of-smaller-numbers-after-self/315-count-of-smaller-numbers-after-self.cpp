class Solution {
public:
    void merge(vector<int> &count, vector<pair<int, int>> &v, int l, int mid,  int r){
        vector<pair<int, int>> temp(r -l + 1);
        int i =l, j = mid + 1, k = 0;
        
        while(i <= mid && j <= r){
            if(v[i].first <= v[j].first){
                temp[k++] = v[j++];
            }
            else{
                count[v[i].second] += r -j + 1;
                temp[k++] = v[i++];
            }
        }
        
        while(i <= mid)
            temp[k++] = v[i++];
        
        while(j <=r)
            temp[k++] = v[j++];
        
        for(int i=l; i<= r; i++){
            v[i] = temp[i - l];
        }
    }   
    void mergeSort(vector<int> &count, vector<pair<int, int>>&v, int l, int r){
        if(l < r){
            int mid = l + (r - l)/2;
            mergeSort(count, v, l, mid);
            mergeSort(count, v, mid +1, r);
            merge(count, v, l, mid, r);
        }
    }    
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> v(n);
        
        for(int i = 0; i < n; i++){
            pair<int, int> p;
            p.first = nums[i];
            p.second = i;
            v[i] = p;
        }
        
        vector<int> count(n, 0);
        mergeSort(count, v, 0, n-1);
        return count;
    }
};