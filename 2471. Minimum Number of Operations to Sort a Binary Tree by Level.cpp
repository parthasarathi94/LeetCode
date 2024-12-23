//Question Link: https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/description/

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

    int minOps(vector<int>&vec){
        int swaps = 0;
        vector<int>sorted(begin(vec), end(vec));
        sort(begin(sorted), end(sorted));

        unordered_map<int, int>mp;
        for(int i=0; i<vec.size(); i++){
            mp[vec[i]] = i;
        }

        for(int i=0; i<vec.size(); i++){
            if(vec[i] == sorted[i]) continue;
            int currIdx = mp[sorted[i]];
            mp[vec[i]] = currIdx;
            mp[vec[currIdx]] = i;
            swap(vec[i], vec[currIdx]);
            swaps++;
        }

        return swaps;
    }

    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int result = 0;
        while(!q.empty()){
            int n = q.size();
            vector<int>vec;
            while(n--){
                TreeNode* temp = q.front();
                q.pop();
                vec.push_back(temp->val);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

            result += minOps(vec);
        }
        return result;
    }
};
