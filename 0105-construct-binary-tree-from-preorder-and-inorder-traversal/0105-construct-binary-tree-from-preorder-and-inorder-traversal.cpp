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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie){
        if(ps>pe||is>ie)
        {
            return nullptr;
        }
        int rootval=preorder[ps];
        TreeNode* root=new TreeNode(rootval);
        int pos=is;
        while(inorder[pos]!=rootval)
        {
            pos++;
        }
        int leftsize=pos-is;
        root->left=build(preorder,inorder,ps+1,ps+leftsize,is,pos-1);
        root->right=build(preorder,inorder,ps+leftsize+1,pe,pos+1,ie);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder,inorder,0,preorder.size()-1,0,inorder.size()-1); 
    }
};