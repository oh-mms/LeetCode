class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> answer;
		for (short i = 0; i < nums.size() - 1; ++i) {
			for (short j = i + 1; j < nums.size(); ++j) {
				if (nums[i] + nums[j] == target) {
					answer.push_back(i);
					answer.push_back(j);
					return answer;
				}
			}
		}
		return answer;
	}
};