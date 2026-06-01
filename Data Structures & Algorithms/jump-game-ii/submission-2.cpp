class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        if(n==1)
            return 0;

        int cnt = 0;
        int i = 0, j = 0;
        i = nums[0];
        while(i<n-1){
            int mx = i;
            while(j<=i){
                mx=max(mx, nums[j]+j);
                j++;
            }
            cnt++;
            i = mx;
        }
        cnt++;
        return cnt;
    }
};
