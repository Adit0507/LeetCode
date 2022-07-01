class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        if(m > n)
           return findMedianSortedArrays(nums2, nums1);
            
        int l = 0, h = m, medianPos = ((m + n)+1)/2;
        while (l <= h){
            int cut1 = (l + h)>>1;  // (l + h)/2
            int cut2 = medianPos - cut1;
            
            int l1 = (cut1 == 0)? INT_MIN:nums1[cut1 - 1];
            int l2 = (cut2 == 0)? INT_MIN:nums2[cut2 -1];  
            int r1 = (cut1 == m)? INT_MAX:nums1[cut1];
            int r2 = (cut2 == n)? INT_MAX:nums2[cut2]; 
            
            if(l1 <= r2 && l2 <=r1){
                if((m + n)%2 != 0)
                    return max(l1, l2);
                else 
                    return (max(l1, l2) + min(r1, r2))/2.0;
            }            
            else if(l1 > r2) h = cut1 - 1;
            else l = cut1 + 1;
        }
        return 0;
    }
};




















