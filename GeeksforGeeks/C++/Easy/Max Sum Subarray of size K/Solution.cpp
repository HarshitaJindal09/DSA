class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        int sum = 0;
        int low = 0;
        int high = k-1;
        for(int i=0;i<=high;i++){
            sum = sum + arr[i];
        }
        int result = sum;
        
        while(high<n){
            low++;
            high++;
            if(high==n){
                break;
            }
            sum = sum-arr[low-1];
            sum=sum+arr[high];
            
            result = max(sum,result);
        }
        return result;
    }
};