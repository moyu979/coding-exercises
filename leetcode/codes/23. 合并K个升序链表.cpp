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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head=new ListNode();
        ListNode* p=head;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> smallq;
        for(int i=0;i<lists.size();i++){
            smallq.push(make_pair(lists[i]->val,lists[i]));
        }
        while(!smallq.empty()){
            p->next=smallq.top().second;
            p=p->next;
            if(p->next){
                smallq.push(make_pair(p->next->val,p->next));
            }
            smallq.pop();
        }
        return head->next;
    }
};