class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* r=new ListNode();
        ListNode* p=r;
        int zero=0;
        do{
            if(l1!=nullptr){
                zero+=l1->val;
                l1=l1->next;
            }
            if(l2!=nullptr){
                zero+=l2->val;
                l2=l2->next;
            }
            ListNode* n=new ListNode();
            n->val=zero%10;
            p->next=n;
            p=p->next;
            zero=zero/10;
        }while(l1!=nullptr || l2!=nullptr || zero!=0);
        r=r->next;

        return r;
    }
};