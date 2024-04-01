#include<algorithm>
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(root==nullptr){
            return ret;
        }
        
        queue<TreeNode*> que;
        TreeNode* tresh=root;
        que.push(root);
        vector<int> temp;
        bool inver=false;
        while(!que.empty()){
            TreeNode* t=que.front();
            que.pop();
            temp.push_back(t->val);
            if(t->left){
                que.push(t->left);
            }
            if(t->right){
                que.push(t->right);
            }

            if(t==tresh){
                tresh=que.back();
                if(inver){
                    reverse(temp.begin(),temp.end());
                }
                inver=!inver;
                ret.push_back(temp);
                temp.clear();
            }
        }
        return ret;
    }
};