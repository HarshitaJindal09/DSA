class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int low = 0;
        int n = s.size();
        int result = INT_MIN;
        unordered_map<char,int> map;
        for(int high=0;high<n;high++){
            map[s[high]]++;
            int k = high-low+1;
            while(map.size()<k){
                map[s[low]]--;
                if(map[s[low]] == 0){
                    map.erase(s[low]);
                }
                low++;
                k = high-low+1;
            }
            if(map.size()==k){
                int len = high-low+1;
                result = max(result,len);
            }
        }
        return result;  
    }
};