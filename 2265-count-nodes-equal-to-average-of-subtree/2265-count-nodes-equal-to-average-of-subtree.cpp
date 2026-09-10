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
private:
    int average(TreeNode* root, int &sum, int &count){
         if (root == nullptr)
            return 0;
        int leftSum = 0, leftCount = 0;
        int rightSum = 0, rightCount = 0;
        average(root->left, leftSum, leftCount);
        average(root->right, rightSum, rightCount);
        sum = leftSum + rightSum + root->val;
        count = leftCount + rightCount + 1;
        return 0;  
    }
public:
    int averageOfSubtree(TreeNode* root) {
        if(root==nullptr)
        {
            return 0;
        }
         int ans = 0;
        function<void(TreeNode*)> solve = [&](TreeNode* node) {
            if (node == nullptr)
                return;
            int sum = 0, count = 0;
            average(node, sum, count);
            if (node->val == sum / count)
                ans++;
            solve(node->left);
            solve(node->right);
        };

        solve(root);
        return ans;

    }
};