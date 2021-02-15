class Solution {
public:
	string convert(string s, int numRows) {
		string answer;
		vector<string> table(numRows);
		bool turn = true; // Forward: true, Reverse: false
		short idx = 0;

		// Insert each element of s in the table.
		for (short i = 0; i < s.size(); ++i) {
			table[idx].push_back(s[i]);

			if (numRows == 1)
				continue;

			// Check Forward or Reverse
			if (turn) {
				if ((idx + 1) > (numRows - 1)) { // Change direction
					idx--;
					turn = false;
				}
				else
					idx++;
			}
			else {
				if ((idx - 1) < 0) { // Change direction
					idx++;
					turn = true;
				}
				else
					idx--;
			}
		}

		for (int i = 0; i < numRows; ++i) {
			for (int j = 0; j < table[i].size(); ++j) {
				answer.push_back(table[i][j]);
			}
		}

		return answer;
	}
};