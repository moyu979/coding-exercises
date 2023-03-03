/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* i=list1,*j=list2;
        ListNode* h=new ListNode(),*p=h;
        while(i && j){
            if(i->val>j->val){
                p->next=j;
                j=j->next;
            }else{
                p->next=i;
                i=i->next;
            }
            p=p->next;
        }
        while(i){
            p->next=i;
            i=i->next;
            p=p->next;
        }
        while(j){
            p->next=j;
            j=j->next;
            p=p->next;
        }
        h=h->next;
        return h;
    }
};