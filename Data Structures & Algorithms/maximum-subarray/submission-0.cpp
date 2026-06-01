class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(), nums.end());

        int sum = 0;
        for(int i=0; i<n; i++){
            sum+=nums[i];
            if(sum<0){
                sum=0;
                continue;
            }
            mx = max(mx, sum);
        }
        return mx;
    }
};
