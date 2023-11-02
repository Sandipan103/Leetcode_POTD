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
    pair<int, pair<int, int>> solve(TreeNode* root)    {
        if(!root)   return {0, {0, 0}};
        pair<int, pair<int, int>> lAns = solve(root->left), rAns = solve(root->right);
        int totalSum = lAns.second.first + rAns.second.first + root->val;
        int totalNode = lAns.second.second + rAns.second.second + 1;
        int ans = lAns.first + rAns.first;
        if(totalSum / totalNode == root->val)  ans++;
        return {ans, {totalSum , totalNode}};
    }

    int averageOfSubtree(TreeNode* root) {
        return solve(root).first;
    }
};