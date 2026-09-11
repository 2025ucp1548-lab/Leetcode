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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
       if(inorder.empty())
       {
        return nullptr;
       } 
       int rootval=postorder.back();
       TreeNode* root=new TreeNode(rootval);
       int pos=0;
       while(inorder[pos]!=rootval)
       {
        pos++;
       }
       vector<int> leftin(inorder.begin(),inorder.begin()+pos);
       vector<int> rightin(inorder.begin()+pos+1, inorder.end());
       vector<int> leftpost(postorder.begin(),postorder.begin()+pos);
       vector<int> rightpost(postorder.begin()+pos,postorder.end()-1);
       root->left=buildTree(leftin,leftpost);
       root->right=buildTree(rightin,rightpost);
       return root;
    }
};