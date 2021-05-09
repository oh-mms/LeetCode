class Solution
{
// Reference Version
public:
	bool CheckSymmetric(TreeNode& lNode, TreeNode& rNode)
	{
		bool flag = true;

		if (lNode.val != rNode.val)
			return false;

		if (lNode.left != nullptr)
		{
			if (rNode.right != nullptr)	flag &= CheckSymmetric(*lNode.left, *rNode.right);
			else										return false;
		}
		else if (rNode.right != nullptr)
			return false;

		if (lNode.right != nullptr)
		{
			if (rNode.left != nullptr)		flag &= CheckSymmetric(*lNode.right, *rNode.left);
			else										return false;
		}
		else if (rNode.left != nullptr)
			return false;

		return flag;
	}

	bool isSymmetric(TreeNode* root)
	{
		TreeNode& refNode = *root;

		if (refNode.left != nullptr && refNode.right != nullptr)
			return CheckSymmetric(*refNode.left, *refNode.right);

		if (refNode.left == nullptr && refNode.right == nullptr)
			return true;

		return false;
	}
};


/*
// Pointer Version
class Solution
{
public:
	bool CheckSymmetric(TreeNode* lNode, TreeNode* rNode)
	{
		bool flag = true;

		if (lNode->val != rNode->val)
			return false;

		if (lNode->left != nullptr)
		{
			if (rNode->right != nullptr) flag &= CheckSymmetric(lNode->left, rNode->right);
			else                         return false;
		}
		else if (rNode->right != nullptr)
			return false;

		if (lNode->right != nullptr)
		{
			if (rNode->left != nullptr) flag &= CheckSymmetric(lNode->right, rNode->left);
			else                        return false;
		}
		else if (rNode->left != nullptr)
			return false;

		return flag;
	}

	bool isSymmetric(TreeNode* root)
	{
		if (root->left != nullptr && root->right != nullptr)
			return CheckSymmetric(root->left, root->right);

		if (root->left == nullptr && root->right == nullptr)
			return true;

		return false;
	}
};
*/