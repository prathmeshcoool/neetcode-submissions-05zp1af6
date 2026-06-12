class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();

        if(find(nums.begin(), nums.end(), target)==nums.end()){
            return {-1,-1};
        }

        auto it1 = lower_bound(nums.begin(), nums.end(), target);
        auto it2 = upper_bound(nums.begin(), nums.end(), target);

        int l = it1 - nums.begin();
        int r = it2 - nums.begin();
        r--;

        return {l,r};
    }
};