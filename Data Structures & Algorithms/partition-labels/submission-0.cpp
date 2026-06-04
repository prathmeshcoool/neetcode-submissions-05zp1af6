class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n  = s.size();
        unordered_set<char> st;
        unordered_map<char,int> mp;

        vector<int> ans;

        for(int i=0; i<n; i++){
            mp[s[i]]++;
        }

        int cnt = 0;
        for(int i=0; i<n; i++){
            mp[s[i]]--;
            cnt++;
            if(mp[s[i]]!=0 && st.count(s[i])==0){
                st.insert(s[i]);
            }

            if(mp[s[i]]==0)
                st.erase(s[i]);
            
            if(st.empty()){
                ans.push_back(cnt);
                cnt = 0;
                continue;
            }
        }

        return ans;

        
    }
};
