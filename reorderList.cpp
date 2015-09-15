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
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: void
     */
    void reorderList(ListNode *head) {
        // write your code here
        if(head == NULL || head->next == NULL) {
            return;
        }

        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = NULL;
        
        ListNode dummy(0);
        while(fast){
            ListNode* n = dummy.next;
            dummy.next = fast;
            ListNode* nn = fast->next;
            fast->next = n;
            fast = nn;
        }
        
        slow = head;
        fast = dummy.next;
        
        while(slow){
            if(fast){
                ListNode* n = slow->next;
                slow->next = fast;
                ListNode* nn = fast->next;
                fast->next = n;
                slow = n;
                fast = nn;
            } else break;
        }
    }
};



