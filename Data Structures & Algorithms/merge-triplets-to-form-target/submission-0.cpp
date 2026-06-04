class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int n = triplets.size();

        bool chk1 = false, chk2 = false, chk3 = false;
        for(auto v:triplets){
            if(v[0]>target[0] || v[1]>target[1] || v[2]>target[2])continue;

            if(v[0]==target[0])chk1=true;
            if(v[1]==target[1])chk2=true;
            if(v[2]==target[2])chk3=true;
        }

        return (chk1 && chk2 && chk3) ? true:false;
    }
};
