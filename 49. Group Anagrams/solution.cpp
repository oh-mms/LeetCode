class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_multimap<string, string> um;
		vector<vector<string>> answer;
		string s;

		for (int i = 0; i < strs.size(); ++i) {
			s = strs[i];
			sort(s.begin(), s.end());
			um.insert(make_pair(s, strs[i]));
		}

		vector<string> vs;
		string key = um.begin()->first;
		for (auto iter = um.begin(); iter != um.end(); ++iter) {
			if (key != iter->first) {
				answer.push_back(vs);
				vs.clear();
				key = iter->first;
			}
			vs.push_back(iter->second);
		}
		if (!vs.empty())
			answer.push_back(vs);

		return answer;
	}
};