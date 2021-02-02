class Solution {
public:
	void sumAndIncreasingIdx(int& sum, int value, int& idx) {
		sum += value;
		idx++;
	}

	int romanToInt(string s) {
		int sum = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == 'C') {
				if (i + 1 < s.size() && s[i + 1] == 'M')
					sumAndIncreasingIdx(sum, 900, i);
				else if (i + 1 < s.size() && s[i + 1] == 'D')
					sumAndIncreasingIdx(sum, 400, i);
				else
					sum += 100;
				continue;
			}

			if (s[i] == 'X') {
				if (i + 1 < s.size() && s[i + 1] == 'C')
					sumAndIncreasingIdx(sum, 90, i);
				else if (i + 1 < s.size() && s[i + 1] == 'L')
					sumAndIncreasingIdx(sum, 40, i);
				else
					sum += 10;
				continue;
			}

			if (s[i] == 'I') {
				if (i + 1 < s.size() && s[i + 1] == 'X')
					sumAndIncreasingIdx(sum, 9, i);
				else if (i + 1 < s.size() && s[i + 1] == 'V')
					sumAndIncreasingIdx(sum, 4, i);
				else
					sum += 1;
				continue;
			}

			switch (s[i]) {
			case 'M':
				sum += 1000;
				break;
			case 'D':
				sum += 500;
				break;
			case 'L':
				sum += 50;
				break;
			case 'V':
				sum += 5;
				break;
			}
		}

		return sum;
	}
};