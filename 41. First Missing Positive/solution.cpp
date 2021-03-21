class Solution {
public:
	int firstMissingPositive(vector<int>& nums)
	{
		int answer = 1;
		if (nums.size() <= 0) return answer;

		int maxValue = nums[0];
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] <= 0) continue;
			maxValue = max(maxValue, nums[i]);
		}

		unordered_map<int, bool> m;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] <= 0) continue;
			m[nums[i]] = true;
		}

		for (int i = 1; i < INT_MAX; ++i)
		{
			if (!m[i])
			{
				answer = i;
				break;
			}
		}

		return answer;
	}
};