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
        ListNode *l3 = new ListNode();
        ListNode*temp = l3;
        int sum;
        int c =0;
        while(l1!=NULL || l2!=NULL ||c){
            sum =0;
            if(l1!=NULL){
                sum+=l1->val;
                l1 = l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2 = l2->next;
            }
            sum+=c;
            temp->next = new ListNode(sum%10);
            c = sum/10;
            temp= temp->next;
        }
        return l3->next;
    }
};