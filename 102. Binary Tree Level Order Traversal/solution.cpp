// solution 1
class Solution {
public:
	void process(vector<vector<int>>& nodesForDepth, TreeNode* node, int depth)
	{
		// ����� ����(������ ��)�� ���� ���� ����� depth(����)���� ������
		// ���� ���� depth ���� ������ ���� �� �ְ� ���͸� ����(resize)
		if (nodesForDepth.size() < depth)
			nodesForDepth.resize(depth);

		nodesForDepth[depth - 1].push_back(node->val); // �ε����� 0���� �����ϴ�

		if (node->left != nullptr)
			process(nodesForDepth, node->left, depth + 1);

		if (node->right != nullptr)
			process(nodesForDepth, node->right, depth + 1);
	}

	vector<vector<int>> levelOrder(TreeNode* root)
	{
		vector<vector<int>> nodesForDepth;

		if (root != nullptr)
		{
			nodesForDepth.resize(1);
			process(nodesForDepth, root, 1);
		}

		return nodesForDepth;
	}
};

/*
// solution 2
class Solution {
public:
	void process(unordered_map<short, vector<int>>& nodesForDepth, TreeNode* node, int depth)
	{
		nodesForDepth[depth].push_back(node->val);

		if(node->left != nullptr)
			process(nodesForDepth, node->left, depth+1);

		if(node->right != nullptr)
			process(nodesForDepth, node->right, depth+1);
	}

	vector<vector<int>> levelOrder(TreeNode* root)
	{
		vector<vector<int>> answer;
		unordered_map<short, vector<int>> nodesForDepth;

		if(root != nullptr)
			process(nodesForDepth, root, 1);

		for(int i = 1; i < 2001; ++i)
		{
			if(nodesForDepth[i].size() <= 0)
				break;
			answer.push_back(nodesForDepth[i]);
		}

		return answer;
	}
};
*/