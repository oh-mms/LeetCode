class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string answer;
		int idx = 0;
		bool flag = false;

		while (strs.size()) {
			for (int i = 0; i < strs.size(); ++i) {
				if (strs[i].size() <= idx) {
					flag = true;
					break;
				}
			}
			if (flag) break;

			char ch = strs[0][idx];
			for (int i = 1; i < strs.size(); ++i) {
				if (ch != strs[i][idx]) {
					flag = true;
					break;
				}
			}

			if (flag) break;

			answer.push_back(strs[0][idx]);
			idx++;
		}

		return answer;
	}
};