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
    if(p==NULL||q==NULL) return p==q;

    //pre-order traversal, push right first then left
    stack<TreeNode*> pp, qq;
    pp.push(p);
    qq.push(q);
    TreeNode* tmp_p;
    TreeNode* tmp_q;
    while(!pp.empty()&&!qq.empty()){
      tmp_p = pp.top();
      tmp_q = qq.top();
      //1
      if(tmp_p==NULL&&tmp_q==NULL){
          pp.pop();qq.pop();
          continue;
      }
      //2
      if(tmp_p==NULL||tmp_q==NULL)
        return false;
      //1
      if(tmp_p->val!=tmp_q->val) return false;
      pp.pop();qq.pop();

      if(tmp_p!=NULL){
        pp.push(tmp_p->right);
        pp.push(tmp_p->left);
      }
      if(tmp_q!=NULL){
        qq.push(tmp_q->right);
        qq.push(tmp_q->left);
      }

    }
      return true;
  }

};
