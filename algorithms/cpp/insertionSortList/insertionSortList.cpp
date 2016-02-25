// Source : https://oj.leetcode.com/problems/insertion-sort-list/
// Author : qingyuanxingsi
// Date   : 2016-02-25

/********************************************************************************** 
* 
* Sort a linked list using insertion sort.
*               
**********************************************************************************/

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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        // head start of sorted
        // p end of sorted
        ListNode* p = head;
        while(p!=NULL && p->next!=NULL){
            ListNode* q = p->next;
            ListNode* s = head;
            if(s->val > q->val){
                //Insert at the head of the list
                p->next = q->next;
                q->next = head;
                head = q;
            }
            else{
                while(s->next->val < q->val){
                    // s->next is the position to insert
                    s = s->next;
                }
                if(s->next!=q){
                    p->next = q->next;
                    q->next = s->next;
                    s->next = q;
                }
                else{
                    p = p->next;
                }
            }
        }
        return head;
    }
};
