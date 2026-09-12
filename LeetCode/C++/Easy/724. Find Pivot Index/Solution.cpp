class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
// This does eventually create the total sum, but only as you move through the loop.
//The cleaner approach is to calculate the total sum first.

        for(int x:nums){
            sum+= x;
        }

        int left = 0;

        if(sum-nums[0] == 0){
            return 0; 
        }
        for(int i=1;i<nums.size();i++){
            left += nums[i-1];
            int right = sum-left-nums[i];
            if(left==right){
                return i;
            }   
        } 
        return -1;   
    }
};