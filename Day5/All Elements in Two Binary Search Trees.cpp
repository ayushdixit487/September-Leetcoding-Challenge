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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        
        if(root1==NULL && root2==NULL)
            return ans;
        else if(root1!=NULL && root2==NULL){
            inorder(root1, ans);
            return ans;
        }
         else if(root2!=NULL && root1==NULL){
            inorder(root2, ans);
            return ans;
        }else{
             vector<int> temp1;
             vector<int> temp2;
             inorder(root1, temp1);
             inorder(root2, temp2);
             merge(temp1,temp2,ans);
         }
        return ans;
    }
    void inorder(TreeNode* root , vector<int> & temp){
        if(root==NULL)
            return ;
        inorder(root->left,temp);
        temp.push_back(root->val);
        inorder(root->right,temp);
    }
    void merge(vector<int> temp1, vector<int> temp2, vector<int> & ans){
        int n =  temp1.size();
        int m =  temp2.size();
        int i = 0,j =0 ;
        while(i<n && j<m){
            if(temp1[i]<=temp2[j]){
                ans.push_back(temp1[i]);
                i++;
            }
            else{
                ans.push_back(temp2[j]);
                j++;
            }
        }
        while(i<n){
            ans.push_back(temp1[i]);
                i++;
        }
         while(j<m){
            ans.push_back(temp2[j]);
                j++;
        } 
    }
};
