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
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if(p==NULL&&q==NULL) return true;
    if(p==NULL||q==NULL) return false;
    bool left, right;
    if(p->val==q->val){
      if(p->left!=NULL||q->left!=NULL) left = isSameTree(p->left, q->left);
      else left = true;

      if(p->right!=NULL||q->right!=NULL) right = isSameTree(p->right,q->right);
      else right = true;
      if(left&&right) return true;
    }
    return false;
  }
};
