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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        TreeNode* root = new TreeNode(0);
        constructTree(root, 0, nums.size() - 1, nums);
        return root;
    }
    
    void constructTree(TreeNode *tree, int start, int end, vector<int>& nums){
        if (start == end){
            tree->val = nums[start];
            return;
        }
        vector<int>::iterator biggest = max_element(begin(nums) + start, begin(nums) + end + 1);
        int index = distance(begin(nums), biggest);
        tree->val = nums[index];
        if (end != index){
            tree->right = new TreeNode(0);
            constructTree(tree->right, index + 1, end, nums);
        }
        if (start != index){
            tree->left = new TreeNode(0);
            constructTree(tree->left, start, index - 1, nums);
        }
    }
};