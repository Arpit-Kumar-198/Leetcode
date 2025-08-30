/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    public:
    bool exist(TreeNode* root, TreeNode* tgt){
        if(root==NULL) return false;
        if(root==tgt) return true;
        return exist(root->left,tgt) || exist(root->right,tgt);
    }
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            if(root==p || root==q) return root;
            else if(exist(root->left,p) && exist(root->right,q)) return root;
            else if(!exist(root->left,p) && !exist(root->right,q)) return root;
            else if(exist(root->left,p) && exist(root->left,q)){
                return lowestCommonAncestor(root->left, p, q);
            }
            else{
               return lowestCommonAncestor(root->right, p, q);
            }
            return NULL;
        }
    };