class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int ans = arr[0];
        int nodelete = arr[0];
        int onedelete = INT_MIN;
        
        for(int i=1;i<arr.size();i++){
            int prevonedelete = onedelete;
            int prevnodelete = nodelete;

            // Maximum sum ending at i without deletion
            nodelete = max(arr[i], prevnodelete +arr[i]);
            
            // Either:
            // 1. Delete arr[i]
            // 2. We already deleted one element before
            if (prevonedelete == INT_MIN)
                onedelete = prevnodelete;
            else
                onedelete = max(prevnodelete, prevonedelete + arr[i]);

            ans = max(ans, max(nodelete,onedelete));
        }
        return ans;
        
    }
};
