class Solution {
public:
	vector<string> letterCombinations(string digits) {
		if (digits.size() < 1) return vector<string>();

		vector<string> chTable(8);
		int startDec = 97;

		// Processing each number.
		for (int i = 0; i < 8; ++i) {
			if (i != 5 && i != 7) {
				chTable[i].push_back(startDec);
				chTable[i].push_back(startDec + 1);
				chTable[i].push_back(startDec + 2);
				startDec += 3;
				continue;
			}
			chTable[i].push_back(startDec);
			chTable[i].push_back(startDec + 1);
			chTable[i].push_back(startDec + 2);
			chTable[i].push_back(startDec + 3);
			startDec += 4;
		}

		// Calc Process
		int size = 1;
		vector<int> nums(digits.size());
		for (int i = 0; i < digits.size(); ++i) {
			nums[i] = digits[i] - 50; // Fit in 0~7 index.
			size *= chTable[nums[i]].size();
		}

		vector<string> v;

		if (nums.size() == 1) {
			string s;
			for (int i = 0; i < chTable[nums[0]].size(); ++i) {
				s.push_back(chTable[nums[0]][i]);
				v.push_back(s);
				s.clear();
			}
		}

		if (nums.size() == 2) {
			string s;
			for (int i = 0; i < chTable[nums[0]].size(); ++i) {
				for (int j = 0; j < chTable[nums[1]].size(); ++j) {
					s.push_back(chTable[nums[0]][i]);
					s.push_back(chTable[nums[1]][j]);
					v.push_back(s);
					s.clear();
				}
			}
		}

		if (nums.size() == 3) {
			string s;
			for (int i = 0; i < chTable[nums[0]].size(); ++i) {
				for (int j = 0; j < chTable[nums[1]].size(); ++j) {
					for (int k = 0; k < chTable[nums[2]].size(); ++k) {
						s.push_back(chTable[nums[0]][i]);
						s.push_back(chTable[nums[1]][j]);
						s.push_back(chTable[nums[2]][k]);
						v.push_back(s);
						s.clear();
					}
				}
			}
		}

		if (nums.size() == 4) {
			string s;
			for (int i = 0; i < chTable[nums[0]].size(); ++i) {
				for (int j = 0; j < chTable[nums[1]].size(); ++j) {
					for (int k = 0; k < chTable[nums[2]].size(); ++k) {
						for (int l = 0; l < chTable[nums[3]].size(); ++l) {
							s.push_back(chTable[nums[0]][i]);
							s.push_back(chTable[nums[1]][j]);
							s.push_back(chTable[nums[2]][k]);
							s.push_back(chTable[nums[3]][l]);
							v.push_back(s);
							s.clear();
						}
					}
				}
			}
		}

		return v;
	}
};