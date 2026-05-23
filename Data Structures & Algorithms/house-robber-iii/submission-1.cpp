/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<pair<TreeNode*, bool>, int> dp;

    int fun(TreeNode* root, bool last){
        int take = 0, donttake=0;

        if(!root){
            return 0;
        }
        if(dp.count({root, last})){
            return dp[{root, last}];
        }
        if(last==true){
            donttake+=fun(root->left, false);
            donttake+=fun(root->right, false);
        }
        else{
            take=root->val;
            take+=fun(root->left,true);
            take+=fun(root->right,true);

            donttake+=fun(root->left, false);
            donttake+=fun(root->right, false);
        }

        return dp[{root,last}]=max(take,donttake);

    }

    int rob(TreeNode* root) {
        dp.clear();        
        return dp[{root, false}] = fun(root, false);
    }
};