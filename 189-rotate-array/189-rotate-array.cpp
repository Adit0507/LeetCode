class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int x = nums.size() - k;    //x is the index of first element of vector nums after k rotations 
        int x1 = x;    // stores the initial value of x

        if(k>nums.size())    // condition for k greater than vector nums size
        {
            x = nums.size() - k%nums.size();
            x1=x;
        }

        vector<int> rotated_vector;   // resulting vector after k rotations

        if(nums.size()==1||k==0||k==nums.size())  // exception for vector size equal to 1
        {
            x = 0;
            rotated_vector.push_back(nums[x]);   //pushing value of nums at x
        }
        else   
        {
            rotated_vector.push_back(nums[x]);   //pushing value of nums at x

            if(x<(nums.size()-1))  //increment of x 
            {
               x++;
            }
            else
            {
                x=0;              //if x points to last element of array
            }

            while(x!=x1&&x<nums.size())  //pushing all the remaining elements in the vector
            {
                 rotated_vector.push_back(nums[x]);

                 if(x<(nums.size()-1))
                 {
                   x++;
                 }
                 else
                 {
                     x=0;
                 }

            }

            if(k!=0&&k!=nums.size()) //swaping vectors if any changes occured in the vector after k rotations.
            {
                nums.swap(rotated_vector);
            }
       }
    }
};