class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n =nums.size();
        
        int l = 0;  	// low pointer
        int m = 0;      // mid pointer
        int h = n -1;      // high ponter
        
        while(m <= h){
            switch(nums[m]) {
                case 0:
                    swap(nums[l++], nums[m++]);
                    break;
                    
                case 1:
    	            m++;
                    break;
                    
                case 2:
                    swap(nums[m], nums[h--]);                    
                    break;
                
            }
        }
    }
};