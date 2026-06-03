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
    vector<string> numbers;

    void dfs(TreeNode* root, string s){
        
        s.push_back(('0'+root->val));

        if(!root->left && !root->right){
            numbers.push_back(s);
            return;
        }
    
        if(root->left)dfs(root->left, s);    
        if(root->right)dfs(root->right, s);    
    }
    
    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
    
        string s;

        dfs(root, s);

        int sum = 0;
        for(auto num:numbers){
            sum+=stoi(num);
        }
        
        return sum;
    }
};