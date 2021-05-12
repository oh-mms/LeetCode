class Solution {
public:
	void process(vector<vector<int>>& nodesForDepth, TreeNode* node, int depth)
	{
		nodesForDepth[depth].push_back(node->val);

		if (node->left != nullptr)
			process(nodesForDepth, node->left, depth + 1);

		if (node->right != nullptr)
			process(nodesForDepth, node->right, depth + 1);
	}

	vector<vector<int>> levelOrder(TreeNode* root)
	{
		vector<vector<int>> answer;
		vector<vector<int>> nodesForDepth(2001);

		if (root != nullptr)
			process(nodesForDepth, root, 1);

		for (int i = 1; i < 2001; ++i)
		{
			if (nodesForDepth[i].size() <= 0)
				break;
			answer.push_back(nodesForDepth[i]);
		}

		return answer;
	}
};