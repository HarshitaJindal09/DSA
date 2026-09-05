class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int low = 0;
        int n = fruits.size();
        int result = INT_MIN;
        unordered_map<int,int> map;
        for(int high = 0;high<n;high++){
            map[fruits[high]]++;
            while(map.size()>2){
                map[fruits[low]]--; 
                if(map[fruits[low]]==0){
                    map.erase(fruits[low]);
                }
                low++;
            }
            if(map.size()==2 || map.size()<2){
                int len = high-low+1;
                result = max(result,len);
            }
        }
        return result;   
    }
};