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
    int result;
    pair<int,int>fun(TreeNode* root){
        if(root==nullptr){
            return{0,0};
        }
        auto p1=fun(root->left);
        auto p2=fun(root->right);
        int totalsum=p1.first+p2.first+root->val;
        int totalcount=p1.second+p2.second+1;
        int avg=totalsum/totalcount;
        if(avg==root->val){
            result+=1;
        }
        return{totalsum,totalcount};
    }
    int averageOfSubtree(TreeNode* root) {
        result=0;
        fun(root);
        return result;
        
    }
};