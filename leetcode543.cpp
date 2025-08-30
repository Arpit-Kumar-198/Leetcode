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
    int maxDia = 0;
    int height(TreeNode* root){
            if(root==NULL) return 0;
            int l = height(root->left);
            int r = height(root->right);
            return 1+max(l,r);
        }
    void helper(TreeNode* root, int &maxDia){
         if(root==NULL) return;
           int dia = height(root->left)+height(root->right);
           maxDia = max(maxDia,dia);
           helper(root->left,maxDia);
          helper(root->right,maxDia);
    }
        int diameterOfBinaryTree(TreeNode* root) {
            int maxDia = 0;
            helper(root,maxDia);
           return maxDia;
    
        }
    };