class Solution {
public:
	void m(vector<vector<string>>& v, int& n) {
		unordered_set<string> s;
		vector<string> r;
		string temp;

		for (int i = v[n - 1].size(); i > 0; --i) {
			temp = "(" + v[n - 1][i - 1] + ")";
			s.insert(temp);
		}

		// Solve using DP.
		for (int i = 1; i < n; ++i) {
			int j = n - i;
			for (int i_idx = v[i].size() - 1; i_idx >= 0; --i_idx) {
				for (int j_idx = v[j].size() - 1; j_idx >= 0; --j_idx) {
					temp = v[i][i_idx] + v[j][j_idx];
					s.insert(temp);
				}
			}
		}

		for (auto& x : s) v[n].push_back(x);
	}

	vector<string> generateParenthesis(int n) {
		vector<string> answer;
		vector<vector<string>> v(9);
		v[0].push_back("");

		for (int i = 1; i <= n; ++i)
			m(v, i);

		answer = v[n];
		return answer;
	}
};