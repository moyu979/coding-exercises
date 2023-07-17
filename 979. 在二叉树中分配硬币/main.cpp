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
    int moves=0;
    int getValue(TreeNode* root){
        root->val--;
        if(root->right!=nullptr){
            int rightMore=getValue(root->right);
            moves=moves+abs(rightMore);
            root->val+=rightMore;
        }
        if(root->left!=nullptr){
            int leftMore=getValue(root->left);
            moves=moves+abs(leftMore);
            root->val+=leftMore;
        }
        return root->val;
    }
    int distributeCoins(TreeNode* root) {
        getValue(root);
        return moves;
    }
};