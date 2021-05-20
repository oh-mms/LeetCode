class Solution {
public:
	void GetPreOrder(TreeNode* endNode, TreeNode* curNode)
	{
		endNode->right = curNode;
		TreeNode* leftNode = curNode->left;
		TreeNode* rightNode = curNode->right;

		curNode->left = nullptr;
		curNode->right = nullptr;

		if (leftNode != nullptr)
		{
			curNode->right = leftNode;
			GetPreOrder(endNode, leftNode);
		}

		if (rightNode != nullptr)
		{
			endNode->right->right = rightNode;
			GetPreOrder(endNode, curNode->right);
		}
	}

	void flatten(TreeNode* root)
	{
		if (root == nullptr)
			return;

		TreeNode* temp = new TreeNode;
		GetPreOrder(temp, root);
	}
};