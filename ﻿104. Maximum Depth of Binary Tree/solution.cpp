class Solution {
public:
	int GetMaxDepth(TreeNode* node, int depth)
	{
		int curDepth = depth;

		if (node->left != nullptr)
			depth = max(depth, GetMaxDepth(node->left, curDepth + 1));

		if (node->right != nullptr)
			depth = max(depth, GetMaxDepth(node->right, curDepth + 1));

		return depth;
	}

	int maxDepth(TreeNode* root) {
		if (root == nullptr)
			return 0;

		return GetMaxDepth(root, 1);
	}
};