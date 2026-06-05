class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int mx = 1;

        int ans = *max_element(nums.begin(), nums.end());

        for(int i=0; i<n; i++){
            mx*=nums[i];
            ans = max(ans, mx);
            if(mx==0){
                mx = 1;
            }
        }
        mx = 1;
        for(int i=n-1; i>=0; i--){
            mx*=nums[i];
            ans = max(ans, mx);
            if(mx==0){
                mx = 1;
            }
        }

        return ans;
    }
};
