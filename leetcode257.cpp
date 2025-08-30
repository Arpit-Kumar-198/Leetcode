class Solution {
    public:
    void helper(TreeNode* root,vector<string>& ans, string s){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL) {
            s += to_string(root->val);
            ans.push_back(s);
            return;
        }
        helper(root->left,ans,s+to_string(root->val)+"->");
        helper(root->right,ans,s+to_string(root->val)+"->");
    }
        vector<string> binaryTreePaths(TreeNode* root) {
            vector<string> ans;
            helper(root,ans,"");
            return ans;
        }
    };