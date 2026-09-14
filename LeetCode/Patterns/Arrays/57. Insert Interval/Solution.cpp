class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> interval1;
        bool insert = false;
        for(int i=0;i<intervals.size();i++){
            if(insert == false && intervals[i][0] >= newInterval[0]){
                insert = true;
                interval1.push_back(newInterval);
            }
            interval1.push_back(intervals[i]);
        }
        if(insert == false){
            interval1.push_back(newInterval); 
        }

        vector<vector<int>> result;
        int start1 = interval1[0][0];
        int end1 = interval1[0][1];

        for(int i=1;i<interval1.size();i++){
            int start2 = interval1[i][0];
            int end2 = interval1[i][1];

            if(end1>=start2){
                start1 = start1;
                end1 = max(end1,end2);
                continue;
            }
            result.push_back({start1,end1});

            start1 = start2;
            end1 = end2;
        }
        result.push_back({start1,end1});

        return result;
    }
};