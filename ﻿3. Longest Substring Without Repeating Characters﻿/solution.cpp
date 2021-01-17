class Solution {
public:

	int lengthOfLongestSubstring(string s) {
		typedef unsigned short Ushort;

		vector<char> table(127);
		Ushort max = 0, temp = 0;

		for (Ushort i = 0; i < s.size(); ++i) {
			for (Ushort j = 0; j < table.size(); ++j) // this is a overhead.
				table[j] = 0;

			for (Ushort j = i; j < s.size(); ++j) {
				if (table[s[j]]) break;
				table[s[j]]++;
				temp = (j - i) + 1;
			}

			if (temp > max)
				max = temp;
		}

		return max;
	}
};