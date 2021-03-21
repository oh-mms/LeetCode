class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> answer;
		sort(nums.begin(), nums.end());
		do
		{
			vector<int> v;
			for (auto& x : nums)
				v.push_back(x);
			answer.push_back(v);
		} while (next_permutation(nums.begin(), nums.end()));

		return answer;
	}
};