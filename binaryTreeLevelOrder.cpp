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
    /**
     * @param root: The root of binary tree.
     * @return: Level order a list of lists of integer
     */
public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        // write your code here
        int height = getHeight(root);
        vector<vector<int>> ret(height);
        if(height == 0) return ret;
        getSolution(root, ret, 0);
        return ret;
    }
    
    void getSolution(TreeNode *root, vector<vector<int>>& ret, int level){
        if(root == NULL)
            return;
        ret[level].push_back(root->val);
        getSolution(root->left, ret,level+1);
        getSolution(root->right, ret, level+1);
    }
    
    int getHeight(TreeNode* root){
        return (root == NULL)? 0:max(getHeight(root->left),getHeight(root->right))+1;
    }
};

