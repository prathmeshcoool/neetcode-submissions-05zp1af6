class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp;

        for(int i:nums){
            mp[i]++;
        }

        int ans = 0;
        for(auto [x,y]:mp){
            if(y==1)return -1;
            ans+=(y+3-1)/3;
        }
        return ans;
    }
};