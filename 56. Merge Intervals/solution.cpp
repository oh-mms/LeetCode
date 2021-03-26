class Solution {
public:
	void InsertVectorToVector(vector<vector<int>>& answer, int start, int end) {
		vector<int> v;
		v.push_back(start);
		v.push_back(end);
		answer.push_back(v);
	}

	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> answer;
		sort(intervals.begin(), intervals.end());

		int start = intervals[0][0], end = intervals[0][1];
		int temp = 0;
		while (temp < intervals.size())
		{
			// 다음 시작 값이 더 크면 끊긴 것임.
			// 여태까지의 결과를 저장하고, 다시 탐색 시작.
			if (end < intervals[temp][0])
			{
				InsertVectorToVector(answer, start, end);
				start = intervals[temp][0];
				end = intervals[temp][1];
				temp++;
				continue;
			}

			// 그렇지 않고, 같거나 작다면 end를 더 확장시켜나감.
			if (end < intervals[temp][1])
				end = intervals[temp][1];
			temp++;
		}
		InsertVectorToVector(answer, start, end);
		return answer;
	}
};