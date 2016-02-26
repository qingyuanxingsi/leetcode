// Source : https://oj.leetcode.com/problems/reverse-nodes-in-k-group/
// Author : qingyuanxingsi
// Date   : 2016-02-26

/********************************************************************************** 
* 
* Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
* 
* If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
* 
* You may not alter the values in the nodes, only nodes itself may be changed.
* 
* Only constant memory is allowed.
* 
* For example,
* Given this linked list: 1->2->3->4->5
* 
* For k = 2, you should return: 2->1->4->3->5
* 
* For k = 3, you should return: 3->2->1->4->5
* 
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* p = head;
        int tag = 1;
        while(tag<=k && p!=NULL){
            p = p->next;
            tag += 1;
        }
        ListNode* reverseHead = head;
        if(tag == k+1){
            reverseHead = reverse(head,p);
            head->next = reverseKGroup(p,k);
        }
        return reverseHead;
    }
    
    ListNode* reverse(ListNode* head, ListNode *p){
        if(head->next == p){
            return head;
        }
        ListNode* q = reverse(head->next,p);
        head->next->next = head;
        head->next = NULL;
        return q;
    }
};
