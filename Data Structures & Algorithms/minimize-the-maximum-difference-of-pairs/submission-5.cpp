class Solution {
public:
    bool fun(int diff, int p, vector<int>&nums){
        int cnt=0;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i+1]-nums[i]<=diff){
                cnt++;
                i++;
            }
        }
        return cnt>=p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int l=0,r=*max_element(nums.begin(),nums.end());

        while(l<r){
            int mid=l+(r-l)/2;
            if(fun(mid,p,nums)){
                r=mid;
            }
            else 
                l=mid+1;
        }      

        return l;
    }
};