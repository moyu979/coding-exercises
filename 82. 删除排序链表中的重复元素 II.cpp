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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* head2=new ListNode();
        head2->next=head;

        ListNode* first=head2;

        bool flag=false;

        if(!first->next){
            return first->next;
        }else if(!first->next->next){
            return first->next;
        }else{
            while(first->next->next){
                if(first->next->val==first->next->next->val){
                    first->next=first->next->next;
                    flag=true;
                }else{
                    if(flag){
                        first->next=first->next->next;
                        flag=false;
                    }else{
                        first=first->next;
                    }
                }
            }
            if(flag){
                        first->next=first->next->next;
                        flag=false;
                    }
            
        }
        return head2->next;
    }
};