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
    int sumRootToLeaf(TreeNode* root) {
        string temp = "";
        int ans = 0;
        if(root==NULL)
            return 0;
      dfs(root,temp,ans);
        return ans;
        
    }
    
    void dfs(TreeNode* root ,string temp , int & ans){
        if(root==NULL)
            return;
        temp = temp+ to_string(root->val);
        if(root->left == NULL && root->right == NULL){
            reverse(temp.begin(),temp.end());
            for(int i=0;i<temp.length();i++){
                ans = ans+ (temp[i]-'0')* (int) pow(2,i);
            }
            return ;
        }
        
        dfs(root->left ,temp , ans);
        dfs(root->right,temp,ans);
    }
};
