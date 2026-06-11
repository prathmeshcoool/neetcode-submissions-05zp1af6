class Solution {
public:
    
    unordered_set<string> st;

    bool fun(int i, string curr, string &s, vector<string>& wordDict, vector<vector<int>> &dp){
        
        if(i==s.size()){
            // cout<<curr<<endl;
            if(st.count(curr)){
                return true;
            }
            else 
                return false;
        }
        int m = curr.size();
        if(dp[i][m]!=-1)
            return dp[i][m];


        curr.push_back(s[i]);
        dp[i][m]=fun(i+1, curr, s, wordDict, dp);

        if(st.count(curr)){
            dp[i][m]|=fun(i+1, "", s, wordDict, dp);
        }

        return dp[i][m];
    }
    
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        
        for(auto x:wordDict){
            st.insert(x);
        }

        string curr;

        return fun(0, curr, s, wordDict, dp);

    }
};
