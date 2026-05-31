class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end());

        int mn=intervals[0][0], mx=intervals[0][1];

        vector<vector<int>> ans;
        for(int i=1; i<n; i++){
            if(intervals[i][0]<=mx){
                mx=max(mx, intervals[i][1]);
            }
            else{
                ans.push_back({mn,mx});
                mn = intervals[i][0], mx = intervals[i][1];
            }
        }
        ans.push_back({mn,mx});

        return ans;
    }
};
