class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int zeros = 0;
        int one = 0;
        int result = 0;
        unordered_map<int,int>mpp;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zeros++;
            } else{
                one++;
            }
            int diff = zeros - one;
            if(diff == 0){
                result = max(result,i+1);
                continue;
            }
            if(mpp.find(diff) == mpp.end()){
                mpp[diff] = i;
            }else{
                result = max(result,i- mpp[diff]);
            }
        }
        return result;
        
    }
};