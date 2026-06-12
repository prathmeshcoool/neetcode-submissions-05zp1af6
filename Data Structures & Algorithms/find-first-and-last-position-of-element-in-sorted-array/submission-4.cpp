class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        auto it1 = lower_bound(nums.begin(), nums.end(), target);
        auto it2 = upper_bound(nums.begin(), nums.end(), target);

        if(it1==nums.end() || *it1!=target){
            return {-1,-1};
        }

        int l = it1 - nums.begin();
        int r = it2 - nums.begin();
        r--;

        return {l,r};
    }
};