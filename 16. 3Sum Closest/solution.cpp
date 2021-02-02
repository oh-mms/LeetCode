class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int min_sum = INT_MAX;
		int min = INT_MAX;
		for (int i = 0; i < nums.size() - 2; ++i) {
			bool flag = false;
			for (int j = i + 1; j < nums.size() - 1; ++j) {
				for (int k = i + 2; k < nums.size(); ++k) {
					int temp_sum = nums[i] + nums[j] + nums[k];
					if (abs(temp_sum - target) < min_sum) {
						min_sum = abs(temp_sum - target);
						min = temp_sum;
					}
					if (min == target) {
						flag = true;
						break;
					}
				}
				if (flag) break;
			}
			if (flag) break;
		}

		return min;
	}
};