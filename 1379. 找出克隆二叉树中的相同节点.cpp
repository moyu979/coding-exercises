/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        if(original==nullptr){
            return nullptr;
        }
        else if(original->val==target->val){
            return cloned;
        }
        else{
            TreeNode* left=getTargetCopy(original->left,cloned->left,target);
            if(left!=nullptr){
                return left;
            }
            left=getTargetCopy(original->right,cloned->right,target);
            return left;
        }
    }
};