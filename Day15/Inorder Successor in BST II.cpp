/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        map<Node* ,bool> visited;
        int ans =INT_MAX;
        inorderSuccessor(node ,visited,ans,node->val);
        if(ans==INT_MAX)
            return NULL;
        
        return new Node(ans);
    }
    
    void inorderSuccessor(Node* node , map<Node* ,bool>& visited ,int & ans ,int minValue){
        if(node==NULL)
            return ;
        
        visited[node] = true;
        if(node->val > minValue && node->val < ans){
            ans = node->val;
        }
        if(node->left!=NULL && visited[node->left]==false){
            inorderSuccessor(node->left , visited ,ans, minValue);
        }
         if(node->parent!=NULL && visited[node->parent]==false){
            inorderSuccessor(node->parent , visited ,ans, minValue);
        }
                if(node->right!=NULL && visited[node->right]==false){
            inorderSuccessor(node->right , visited ,ans, minValue);
        }
    }
};
