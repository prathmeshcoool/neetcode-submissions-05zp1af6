class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;

        int s = newInterval[0], e = newInterval[1];
        for(int i=0;i<n;i++){
            if(intervals[i][1]<s)
                ans.push_back({intervals[i][0],intervals[i][1]});
            else if(intervals[i][0]<=e){
                s = min(s,intervals[i][0]);
                e = max(e,intervals[i][1]);
            }
        }
        ans.push_back({s,e});

        for(int i=0;i<n;i++){
            if(intervals[i][0]>e)ans.push_back({intervals[i][0],intervals[i][1]});
        }

        return ans;

    }
};
