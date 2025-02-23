//Question Link: https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/description/

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

    TreeNode* solve(int preStart, int preEnd, int postStart, vector<int>& preorder, vector<int>& postorder){
        if(preStart > preEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[preStart]);
        if(preStart == preEnd) return root;
        int nextNode = preorder[preStart+1];
        int j = postStart;
        while(postorder[j] != nextNode) j++;
        int num = j - postStart + 1;

        root->left = solve(preStart+1, preStart+num, postStart, preorder, postorder);
        root->right = solve(preStart+num+1, preEnd, j+1, preorder, postorder);

        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();
        return solve(0, n-1, 0, preorder, postorder);
    }
};
