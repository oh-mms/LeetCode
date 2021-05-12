// solution 1
class Solution {
public:
	void process(vector<vector<int>>& nodesForDepth, TreeNode* node, int depth)
	{
		// 노드의 개수(레벨의 수)가 현재 들어온 노드의 depth(레벨)보다 적으면
		// 새로 들어온 depth 층의 노드들을 담을 수 있게 백터를 생성(resize)
		if (nodesForDepth.size() < depth)
			nodesForDepth.resize(depth);

		nodesForDepth[depth - 1].push_back(node->val); // 인덱스는 0부터 시작하니

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