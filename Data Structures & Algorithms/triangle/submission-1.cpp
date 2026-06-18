class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n, 0);        
        
        dp[0] = triangle[0][0];
        for(int i=1; i<n; i++){
            int prev;
            for(int j=0; j<triangle[i].size(); j++){
                if(j==0){
                    // cout<<dp[j]<<" "<<" "<<" "<<triangle[i][j]<<endl;
                    prev = dp[j];
                    dp[j] = triangle[i][j] + dp[j];
                }
                else if(j==triangle[i].size()-1){
                    // cout<<" "<<" "<<dp[j-1]<<" "<<triangle[i][j]<<endl;
                    dp[j] = triangle[i][j] + prev;
                }
                else{
                    // cout<<dp[j]<<" "<<dp[j-1]<<" "<<triangle[i][j]<<endl;
                    int temp = dp[j];
                    dp[j] = triangle[i][j] + min(dp[j], prev);
                    prev = temp;
                }
                // cout<<dp[j]<<" ";
            }
            // cout<<endl;
        }
        int ans = INT_MAX;
        for(int i=0; i<n; i++){
            // cout<<dp[i]<<endl;
            ans = min(ans, dp[i]);
        }

        return ans;

    }
};