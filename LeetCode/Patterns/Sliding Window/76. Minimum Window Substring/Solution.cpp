class Solution {
public:
    bool f(vector<int>&have, vector<int>&needed){
        for(int i=0;i<256;i++){
            if(have[i]<needed[i]){
                return false;
            }
        }
        return true;
    }

    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<int> have(256,0);
        vector<int> needed(256,0);

        int low = 0;
        int result = INT_MAX;
        int start = 0;

        for(int i=0;i<m;i++){
            needed[t[i]]++;
        }

        for(int high=0;high<n;high++){
            have[s[high]]++;

            while(f(have,needed)){
                int len = high-low+1;
                if(result>len){
                    result=len;
                    start=low;
                }
                have[s[low]]--;
                low++;
            }    
        }
        if(result==INT_MAX){
            return "";
        }
        return s.substr(start,result);   
    }
};