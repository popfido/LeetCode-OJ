/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution{
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode * deleteDuplicates(ListNode *head) {
        // write your code here
        ListNode head_dummy(0);
        head_dummy.next = head;
        ListNode *p = &head_dummy;
        ListNode *q = head_dummy.next;
        bool dup = false;
        while(q!=NULL){
            while (q->next && q->next->val == q->val){
                dup = true;
                q = q->next;
            }
            if (dup) {
                p->next = q->next;
                q = p->next;
                dup = false;
            }
            else {
                q = q->next;
                p = p->next;
            }
        }
        return head_dummy.next;
    }
};
