class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int a = nums.size();
        vector<int> pos;
        vector<int> neg;
        for(int i=0;i<a;i++){
            if(nums[i]>=0){
                pos.push_back(nums[i]);
            } else{
                neg.push_back(nums[i]);
            }
        }
        if(pos.size()==0){
            for(int i=0;i<neg.size();i++){
                neg[i] = neg[i]*neg[i];
            }
            reverse(neg.begin(),neg.end());
            return neg;
        }
        if(neg.size()==0){
            for(int i=0;i<pos.size();i++){
                pos[i] = pos[i]*pos[i];
            }
            return pos;
        }
        int i = 0;
        int j = 0;
        int index = 0;
        int n = neg.size();
        int m = pos.size();
        vector<int>result(n+m);
        for(int i=0;i<n;i++){
            neg[i] = neg[i]*neg[i];   
        }
        reverse(neg.begin(),neg.end());

        for(int i=0;i<m;i++){
            pos[i] = pos[i]*pos[i];
        }
        while(i<n && j<m){
            if(neg[i]<pos[j]){
                result[index] = neg[i];
                i++;
                index++;
            } else{
                result[index] = pos[j];
                j++;
                index++;
            }
        }
        while(i<n){
            result[index] = neg[i];
            i++;
            index++;
        }
        while(j<m){
            result[index] = pos[j];
            j++;
            index++;
        }
        return result;
    }
};