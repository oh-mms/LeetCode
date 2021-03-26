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
			// ���� ���� ���� �� ũ�� ���� ����.
			// ���±����� ����� �����ϰ�, �ٽ� Ž�� ����.
			if (end < intervals[temp][0])
			{
				InsertVectorToVector(answer, start, end);
				start = intervals[temp][0];
				end = intervals[temp][1];
				temp++;
				continue;
			}

			// �׷��� �ʰ�, ���ų� �۴ٸ� end�� �� Ȯ����ѳ���.
			if (end < intervals[temp][1])
				end = intervals[temp][1];
			temp++;
		}
		InsertVectorToVector(answer, start, end);
		return answer;
	}
};