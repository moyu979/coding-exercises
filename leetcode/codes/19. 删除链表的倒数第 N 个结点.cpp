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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* hl=new ListNode();
        hl->next=head;
        ListNode* first=hl,*second=hl;
        while(second->next && n>0){
            second=second->next;
            n--;
        }
        while(second->next){
            second=second->next;
            first=first->next;
        }
        if(first==head){
            if(head->next){
                head->next=head->next->next;
            }else{
                head=nullptr;
            }
            
        }else{
            first->next=first->next->next;
        }
        head=hl->next;
        return head;
    }
};