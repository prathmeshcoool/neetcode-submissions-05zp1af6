class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mx = 1, mn = 1;

        int ans = *max_element(nums.begin(), nums.end());
        for(int i=0; i<n; i++){
            int prevMx = mx, prevMn = mn; 
            mx = max(nums[i], max(prevMx*nums[i], prevMn*nums[i]));
            mn = min(nums[i], min(prevMx*nums[i], prevMn*nums[i]));

            ans = max(ans, mx);
            
            if(mx==0)mx = 1;
            if(mn==0)mn = 1;

        }

        return ans;
    }
};
