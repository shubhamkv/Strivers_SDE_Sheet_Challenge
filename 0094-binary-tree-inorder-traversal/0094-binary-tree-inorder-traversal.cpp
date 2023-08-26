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
    // void inorder(TreeNode* root)
    // {
    //     if(root==NULL)
    //        return;
    //     inorder(root->left);
    //     ans.push_back(root->val);
    //     inorder(root->right);
    // }
    // vector<int> inorderTraversal(TreeNode* root) {
        
    //     inorder(root);
    //     return ans;
    // }

    // -----------------------------------------------------------------------------

    // Morris Traversal
    
    // vector<int> inorderTraversal(TreeNode* root) {

    //     vector<int> ans;
    //     if(!root)
    //       return ans;
    //     TreeNode* curr = root;
    //     while(curr!=NULL)
    //     {
    //         if(curr->left==NULL)
    //         {
    //            ans.push_back(curr->val);
    //            curr=curr->right;
    //         }
    //         else
    //         {
    //            TreeNode* prev=curr->left;
    //            while(prev->right && prev->right!=curr)
    //               prev = prev->right;
    //            if(prev->right==NULL)
    //            {
    //               prev->right=curr;
    //               curr=curr->left;
    //            }
    //            else
    //            {
    //               prev->right=NULL;
    //               ans.push_back(curr->val);
    //               curr=curr->right;
    //            }
    //         }
    //     }
    //     return ans;
    // }

    // ------------------------------------------------------------------------------------------

    // Iterative Solution 
    
    vector<int> inorderTraversal(TreeNode* root) {
    vector<int> ans;
    TreeNode* node = root;
    stack<TreeNode*> s;

    if(!root)
      return ans;

    while(true)
    {
        if(node)
        {
            s.push(node);
            node=node->left;
        }
        else
        {
            if(s.empty())
               break;
            node=s.top();
            s.pop();
            ans.push_back(node->val);
            node=node->right;
        }
    }
    return ans;
    }
};