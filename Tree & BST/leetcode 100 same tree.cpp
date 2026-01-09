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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        TreeNode* root1=p;
        TreeNode* root2=q;
      if(root2==NULL || root1== NULL)
      return root1==root2;
      
      bool left_identical= isSameTree(root1->left, root2->left);
      bool right_identical= isSameTree(root1->right, root2->right);
      return left_identical && right_identical && root2->val== root1->val;
      
      
      
  
    }
};
