/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    TreeNode* createBalancedTree(vector<int> &v, int start, int end){
        if(start > end)
            return NULL;
        int mid = start + (end-start)/2;
        TreeNode* node = new TreeNode(v[mid]);
        node->left = createBalancedTree(v, start, mid-1);
        node->right = createBalancedTree(v, mid+1, end);
        return node;
    }
    
    void inOrderTraversal(TreeNode* root, vector<int> &v){
        if(root == NULL)
            return;
        inOrderTraversal(root->left, v);
        v.push_back(root->val);
        inOrderTraversal(root->right, v);
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> v;
        inOrderTraversal(root, v);
        return createBalancedTree(v, 0, v.size()-1);
    }
};