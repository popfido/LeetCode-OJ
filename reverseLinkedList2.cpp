/**
 * Definition of singly-linked-list:
 * 
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *        this->val = val;
 *        this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // write your code here
        if(!head||m==n) return head;
        ListNode dummy(0);
        dummy.next = head;
        ListNode *p = &dummy;
        ListNode *q = p;
        
        for(int i=1;i<m;i++)
            p = p->next;
        
        q = p->next;
        
        for(int i=m;i<n;i++){
            ListNode* nn = q->next;
            q->next = nn->next;
            nn->next = p->next;
            p->next = nn;
        }
        
        return dummy.next;
    }
};

