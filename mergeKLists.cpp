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
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        if(lists.empty()) return NULL;
        ListNode head_dummy(INT_MIN);
        ListNode* cur = &head_dummy;
        vector<int> list_val = vector<int>(lists.size(),INT_MAX);
        for (int i=0; i<list_val.size();i++)
            if(lists[i]) list_val[i] = lists[i]->val;
        int pos;
        while(true){
            pos = std::min_element(list_val.begin(), list_val.end()) - list_val.begin();
            if(list_val[pos] == INT_MAX) break;
            cur->next = lists[pos];
            cur = cur->next;
            lists[pos] = lists[pos]->next;
            if(lists[pos]) list_val[pos] = lists[pos]->val;
            else list_val[pos] = INT_MAX;
        }
        return head_dummy.next;
    }
};



