/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *ptr=head,*next;
        while(ptr!=nullptr){
            next=ptr->next;
            ptr->next=head;
            ptr=next;
            if(next!=nullptr && next->next==head){
                return true;
            }
        }
        return false;
    }
};