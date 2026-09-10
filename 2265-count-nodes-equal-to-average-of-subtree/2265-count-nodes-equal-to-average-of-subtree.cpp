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
    int matchingNodes = 0;

    // Returns {subtree_sum, subtree_count}
    pair<int, int> dfs(TreeNode* node) {
        if (!node) return {0, 0};

        auto [leftSum, leftCount] = dfs(node->left);
        auto [rightSum, rightCount] = dfs(node->right);

        int totalSum = node->val + leftSum + rightSum;
        int totalCount = 1 + leftCount + rightCount;

        // Integer division automatically rounds down for positive numbers
        if (node->val == totalSum / totalCount) {
            matchingNodes++;
        }

        return {totalSum, totalCount};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return matchingNodes;
    }
};