class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int l=0,sum=0,ans=0;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            while(sum>goal){
                sum-=nums[l];
                l++;
            }
            int id=l,curr=sum;

            while(curr==goal && id<=i){
                ans++;
                curr-=nums[id];
                id++;
            }
        }
        return ans;
    }
};