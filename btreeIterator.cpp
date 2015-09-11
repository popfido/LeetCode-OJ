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
 * Example of iterate a tree:
 * Solution iterator = Solution(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */
class Solution {
public:
    //@param root: The root of binary tree.
    TreeNode* cur;
    TreeNode* his;
    Solution(TreeNode *root) {
        // write your code here
        cur = root;
        his = NULL;
    }

    //@return: True if there has next node, or false
    bool hasNext() {
        // Morrise Algorithm
        if(his != NULL)
            return true;
        while (cur != NULL) {
            if (cur->left == NULL) {
                his = cur;
                cur = cur->right;
                return true;
            } else {
                TreeNode* pre = cur->left;
                while (pre->right != NULL && pre->right != cur) {
                    pre = pre->right;
                }
                if (pre->right == NULL) {
                    pre->right = cur;
                    cur = cur->left;
                } else {
                    pre->right = NULL;
                    his = cur;
                    cur = cur->right;
                    return true;
                }
            }
        }
        return false;
    }
    
    //@return: return next node
    TreeNode* next() {
        // write your code here
        TreeNode* ret;
        if(his != NULL){
            ret = his;
            his = NULL;
            return ret;
        } 
        while (cur != NULL) {
            if (cur->left == NULL) {
                ret = cur;
                cur = cur->right;
                return ret;
            } else {
                TreeNode* pre = cur->left;
                while (pre->right != NULL && pre->right != cur) {
                    pre = pre->right;
                }
                if (pre->right == NULL) {
                    pre->right = cur;
                    cur = cur->left;
                } else {
                    pre->right = NULL;
                    ret = cur;
                    cur = cur->right;
                    return ret;
                }
            }
        }
    }
};
