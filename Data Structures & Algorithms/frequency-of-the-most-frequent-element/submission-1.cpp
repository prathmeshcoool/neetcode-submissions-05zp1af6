class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();

        sort(nums.begin(),nums.end());

        int l=0, sumdiff=0;
        int ans=1;
        for(int i=1;i<n;i++){
            int diff=(nums[i]-nums[i-1]);
            sumdiff+=diff*(i-l);
            while(sumdiff>k){
                sumdiff-=(nums[i]-nums[l]);
                l++;
            }
            ans=max(ans, i-l+1);
        }
        return ans;
    }
};