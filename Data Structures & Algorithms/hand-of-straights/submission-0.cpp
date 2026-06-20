class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n  = hand.size();
        map<int,int> mp;

        for(auto x:hand){
            mp[x]++;
        }

        int cnt = 0;
        while(!mp.empty()){
            int prev = -1;
            cnt = 0;

            for(auto &[x,y]: mp){
                if(cnt==groupSize)break;
                cnt++;
                if(prev!=-1 && x-prev!=1){
                        return false;
                }
                prev = x;
                y--;
                if(y==0){
                    mp.erase(x);
                }
            }
        }

        if(cnt!=groupSize)return false;

        return true;
    }
};
