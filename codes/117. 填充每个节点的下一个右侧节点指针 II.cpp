/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root){
            return root;
        }
        queue<Node*> tree;
        Node* now,*now2;
        tree.push(root);
        now=root;
        while(!tree.empty()){
            Node* judge=tree.front();
            tree.pop();
            if(judge==nullptr){
                ;
            }else{
                
                if(judge->left){
                    tree.push(judge->left);
                    now2=judge->left;
                }

                if(judge->right){
                    tree.push(judge->right);
                    now2=judge->right;
                }

                if(judge==now){
                    judge->next=nullptr;
                    now=now2;
                }else{
                    judge->next=tree.front();
                }
            
            }
            
            
            
            
            
            

        }
        return root;

    }
};