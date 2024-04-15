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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1=inverse(l1);
        l2=inverse(l2);
        ListNode* ans=new ListNode(0);
        ListNode* now=ans;
        int temp=0;
        while(l1!=nullptr || l2!=nullptr || temp!=0){
            now->val+=temp;
            if(l1!=nullptr){
                now->val+=l1->val;
                l1=l1->next;
            }
            if(l2!=nullptr){
                now->val+=l2->val;
                l2=l2->next;
            }
            temp=now->val/10;
            now->val=now->val%10;
            now->next=new ListNode(0);
            now=now->next;
        }
        ans=inverse(ans);
        if(ans->val==0){
            ListNode* temp=ans;
            ans=ans->next;
            delete(temp);
        }
        return ans;
    }

    ListNode* inverse(ListNode* l1){
        ListNode* ll1=l1;
        l1=l1->next;
        ll1->next=nullptr;
        while(l1!=nullptr){
            ListNode* temp=l1;
            l1=l1->next;
            temp->next=ll1;
            ll1=temp;
        }
        return ll1;
    }
};