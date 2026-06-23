class Solution {
public:
    string reorganizeString(string s) {
        int n = s.size();
        priority_queue<pair<int,char>> pq;

        unordered_map<char, int> mp;
        int mx = 0;
        for(int i=0; i<n; i++){
            mp[s[i]]++;
            mx = max(mx, mp[s[i]]);
        }

        if((n+1)/2 < mx) return "";

        for(auto [x,y]:mp){
            pq.push({y,x});
        }

        string res;
        while(pq.size()){
            if(pq.size()==1){
                pair<int,char> p = pq.top(); pq.pop();
                res.push_back(p.second);
                continue;
            }
            pair<int, char> p = pq.top(); pq.pop();
            res.push_back(p.second);

            pair<int, char> p2 = pq.top(); pq.pop();
            res.push_back(p2.second);

            p2.first--;
            p.first--;

            if(p.first)
                pq.push(p);
            if(p2.first)
                pq.push(p2);

        }
        return res;
    }
};