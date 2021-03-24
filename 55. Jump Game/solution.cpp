class Solution {
public:
	bool Jump(vector<int>& nums, int index, int target) {
		if (index >= target)
			return true;

		if (nums[index] == 0)
			return false;

		int maxIdx = -1;
		for (int i = nums[index]; i >= 1; --i) {
			if (index + i > target)                    	return true;
			if (maxIdx < index + i + nums[index + i])       maxIdx = index + i + nums[index + i];
			else                                     	continue;
			if (Jump(nums, index + i, target))          	return true;
		}

		return false;
	}

	bool canJump(vector<int>& nums) {
		if (nums.size() < 2)
			return true;

		bool b;
		if (Jump(nums, 0, nums.size() - 1)) b = true;
		else                             b = false;

		return b;
	}
};
