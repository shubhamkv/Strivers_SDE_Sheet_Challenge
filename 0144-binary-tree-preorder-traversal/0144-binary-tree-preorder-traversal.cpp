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
    // Recursive Approach 

    // vector<int> ans;
    // void preorder(TreeNode* root)
    // {
    //     if(root==NULL)
    //       return;
    //     ans.push_back(root->val);
    //     preorder(root->left);
    //     preorder(root->right);
    // }
    // vector<int> preorderTraversal(TreeNode* root) {
           
    //     preorder(root);
    //     return ans;
    // }

// -----------------------------------------------------------------------------------------
    // Iterative Approach
    
    // vector<int> preorderTraversal(TreeNode* root) {
   
    //   vector<int> ans;
    //   if(root==NULL)
    //      return ans;
    //   stack<TreeNode*>s;
    //   s.push(root);

    //   while(!s.empty())
    //   {
    //     TreeNode* temp = s.top();   // we can take root = s.top();
    //     s.pop();
    //     ans.push_back(temp->val);   // then here it will root->val
    //     if(temp->right!=NULL)
    //        s.push(temp->right);
    //     if(temp->left!=NULL)
    //        s.push(temp->left);
    //   }
    //   return ans;
    // }
// -----------------------------------------------------------------------------------------------
    //   Morris Traversal 
    
    vector<int> preorderTraversal(TreeNode* root) {
          
        vector<int> ans;
        if(!root)
          return ans;
        TreeNode* curr= root;
        while(curr)
        {
            if(curr->left==NULL)
            {
                ans.push_back(curr->val);
                curr=curr->right;
            }
            else
            {
                TreeNode* prev = curr->left;
                while(prev->right && prev->right!=curr)
                   prev=prev->right;
                if(prev->right==NULL)
                {
                    prev->right=curr;
                    ans.push_back(curr->val);
                    curr=curr->left;
                }
                else
                {
                    prev->right=NULL;
                    curr=curr->right;
                }
            }
        }
        return ans;
    }   
};