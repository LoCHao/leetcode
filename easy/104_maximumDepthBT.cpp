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
    int maxDepth(TreeNode* root) {
        
       return travel(root,0);
        
    }
    
    int travel(TreeNode* root,int depth){
        
        if(root==NULL) return depth;
        
        depth+=1;
        
        int leftdepth = travel(root->left,depth);
        int rightdepth = travel(root->right,depth);
        
        return leftdepth > rightdepth ? leftdepth:rightdepth;
        
    }
  
    //參考解答
    int referenceSolution(TreeNode* root){
      
      if(root==NULL)return 0;
      
      else
          return max(maxDepth(root->left),maxDepth(root->right))+1;
      
    }
      
};
