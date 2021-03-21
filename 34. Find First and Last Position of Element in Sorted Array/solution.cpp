class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> answer{ -1, -1 };

		if (!nums.size())
			return answer;

		auto start_iter = lower_bound(nums.begin(), nums.end(), target);
		auto end_iter = upper_bound(nums.begin(), nums.end(), target);

		if (start_iter == nums.end())
			return answer;

		if (*start_iter != target)
			return answer;

		answer[0] = start_iter - nums.begin();
		answer[1] = (end_iter - 1) - nums.begin();
		return answer;
	}
};