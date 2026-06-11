class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> st;

        for(auto x:wordDict){
            st.insert(x);
        }

        vector<int> dp(n, 0);
        for(int i=0; i<n; i++){
            string curr;
            for(int j=i; j<n; j++){
                if(i>0 && !dp[i-1])break;
                curr.push_back(s[j]);
                if(st.count(curr)){
                    if(i==0){
                        dp[j] = 1;
                        continue;
                    }
                    if(dp[i-1]){
                        dp[j] = 1;
                    }
                }
            }
        }

        return dp[n-1];


    }
};
