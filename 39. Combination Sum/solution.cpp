class Solution {
public:
	bool findCombination(vector<int>& candidates,
		vector<int> v,
		int remain,
		vector<vector<int>>& answer)
	{
		if (remain <= 0) {
			if (remain == 0)
				answer.push_back(v);
			return true;
		}

		for (int i = 0; i < candidates.size(); ++i)
		{
			if (candidates[i] >= v[v.size() - 1])
			{
				v.push_back(candidates[i]);
				if (findCombination(candidates, v, remain - candidates[i], answer))
				{
					v.pop_back();
					return false;
				}
				v.pop_back();
			}
		}
		return false;
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target)
	{
		vector<vector<int>> answer;
		sort(candidates.begin(), candidates.end());

		for (int i = 0; i < candidates.size(); ++i)
		{
			vector<int> v;
			int remain = target - candidates[i];
			v.push_back(candidates[i]);
			findCombination(candidates, v, remain, answer);
		}

		return answer;
	}
};