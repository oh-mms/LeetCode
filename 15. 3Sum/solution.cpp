class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> answer;
		if (nums.size() < 3) return answer;

		sort(nums.begin(), nums.end());

		int lIdx = 0, rIdx = nums.size() - 1, target;

		while (lIdx < rIdx) {
			// Find third number using binary search.
			target = -nums[lIdx] - nums[rIdx];
			if (binary_search(nums.begin() + lIdx + 1, nums.end() - (nums.size() - rIdx), target)) {
				vector<int> vec{ nums[lIdx], target, nums[rIdx] };
				answer.push_back(vec);

				while (lIdx < rIdx && nums[lIdx] == nums[lIdx + 1]) lIdx++;
				while (lIdx < rIdx && nums[rIdx] == nums[rIdx - 1]) rIdx--;
			}

			rIdx--;
			if (lIdx >= rIdx - 1) {
				rIdx = nums.size() - 1;
				lIdx++;
			}
		}

		return answer;
	}
};