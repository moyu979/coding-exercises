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
 #include<stdio.h>
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* i=head,*j=head;
        while(j!=NULL && j->next!=NULL){

            i=i->next;
            j=j->next;
            if(j!=NULL){
                j=j->next;
            }
        }
        return i;
    }
};