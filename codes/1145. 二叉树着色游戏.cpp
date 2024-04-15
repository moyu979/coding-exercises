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
 /*
 两节点不可能在同一层碰上，因此必由高低，在碰撞后，低的层只能获得最高节点以下的节点
 模拟游戏过程了，效率挺低的，别人那个理论推导算法绝了
 */
class Solution {
    struct Node{
        int val,level;
        Node* parent=nullptr,*left=nullptr,*right=nullptr;
    };
public:
    Node* nroot;
    Node* xp,*yp;
    int n;
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        nroot=new Node();
        getTree(root,nroot,1);
        xp=findp(x,this->nroot);
        this->n=n;
        for(int i=1;i<=n;i++){
            yp=findp(i,this->nroot);
            printf("--%d,%d\n",xp->val,yp->val);
            if(check()){
                return true;
            }
        }
        return false;
    }
    bool check(){
        if(yp==xp){
            return false;
        }
        Node* xn=xp;
        Node* yn=yp;
        while(xn->parent!=yn && yn->parent!=xn){
            if(xn->level==yn->level){
                xn=xn->parent;
                if(yn->parent==xn){
                    return fin(nullptr,yn);
                }else{
                    yn=yn->parent;
                }
            }else if(yn->level<xn->level){
                Node* temp=xn;
                while(temp->level!=1 && temp->parent!=yn){
                    temp=temp->parent;
                }
                if(xn->parent==yn){
                    return fin(xn,nullptr);
                }else if(xn->parent->parent==yn){
                    return fin(xn->parent,nullptr);
                }else if(temp->level!=1){
                    xn=xn->parent;
                    yn=temp;
                }else{
                    xn=xn->parent;
                    yn=yn->parent;
                }
            }else{
                Node* temp=yn;
                while(temp->level!=1 && temp->parent!=xn){
                    temp=temp->parent;
                }
                if(yn->parent==xn){
                    return fin(nullptr,xn);
                }else if(yn->parent->parent==xn){
                    return fin(nullptr,yn->parent);
                }else if(temp->level!=1){
                    yn=yn->parent;
                    xn=temp;
                }else{
                    xn=xn->parent;
                    yn=yn->parent;
                }
            }
        }
            if(xn->parent==yn){
                return fin(xn,nullptr);
            }else{
                return fin(nullptr,yn);
            }
        
        printf("---");
        return false;
    }
    bool fin(Node *x,Node* y){
        int size=0;
        if(x==nullptr){
            count(y,size);
            if(size>n/2){
                return true;
            }else{
                return false;
            }
            printf("y");
        }else if(y==nullptr){
            count(x,size);
            if(size>n/2){
                return false;
            }else{
                return true;
            }
            printf("x");
        }else{
            return false;
        }
    }
    void count(Node* r,int & size){
        if(r!=nullptr){
            size++;
            count(r->left,size);
            count(r->right,size);
        }
    }
    Node* findp(int x,Node* root){
        if(root==nullptr){
            return nullptr;
        }
        if(root->val==x){
            return root;
        }else{
            Node* r=findp(x,root->right);
            Node* l=findp(x,root->left);
            if(r!=nullptr)
                return r;
            else if(l!=nullptr)
                return l;
            else 
                return nullptr;
        }
    }
    void getTree(TreeNode* root,Node*& nroot,int level){
        if(root==nullptr){
            nroot=nullptr;
            return;
        }
        else{
            Node* r=new Node();
            nroot=r;
            r->val=root->val;
            r->level=level;
            getTree(root->left,nroot->left,level+1);
            getTree(root->right,nroot->right,level+1);
            if(nroot->left!=nullptr){
                nroot->left->parent=nroot;
            }
            if(nroot->right!=nullptr){
                nroot->right->parent=nroot;
            }
        }
    }
};