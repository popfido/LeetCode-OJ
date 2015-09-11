/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of the binary search tree.
     * @param k1 and k2: range k1 to k2.
     * @return: Return all keys that k1<=key<=k2 in ascending order.
     */
    vector<int> searchRange(TreeNode* root, int k1, int k2) {
        // write your code here
        vector<int> ret = vector<int>();
        if (root == NULL) return ret;
        stack<TreeNode*> s;
        TreeNode* p = root;
        while(p || s.size()){
            while(p) {
                s.push(p);
                p = p->left;
            }

            if(!s.empty()) {
                p = s.top();
                if(p->val >= k1 && p->val <= k2)
                    ret.push_back(p->val);
                s.pop();
                p = p->right;
            }
        }
        return ret;
    }
};
