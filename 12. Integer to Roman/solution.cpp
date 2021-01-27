class Solution {
public:
	string intToRoman(int num) {
		// greedy
		string answer;
		int temp;

		while (num >= 1) {
			// 1000
			if (num / 1000) {
				short count = 0;
				for (int i = 1; i <= num / 1000; ++i) {
					answer.push_back('M');
					count++;
				}
				num -= count * 1000;
				continue;
			}

			// 900
			if (num / 900) {
				answer.push_back('C');
				answer.push_back('M');
				num -= 900;
				continue;
			}

			// 500
			if (num / 500) {
				answer.push_back('D');
				num -= 500;
				continue;
			}

			// 400
			if (num / 400) {
				answer.push_back('C');
				answer.push_back('D');
				num -= 400;
				continue;
			}

			// 100
			if (num / 100) {
				short count = 0;
				for (int i = 1; i <= num / 100; ++i) {
					answer.push_back('C');
					count++;
				}
				num -= count * 100;
				continue;
			}

			// 90
			if (num / 90) {
				answer.push_back('X');
				answer.push_back('C');
				num -= 90;
				continue;
			}

			// 50
			if (num / 50) {
				answer.push_back('L');
				num -= 50;
				continue;
			}

			// 40
			if (num / 40) {
				answer.push_back('X');
				answer.push_back('L');
				num -= 40;
				continue;
			}

			// 10
			if (num / 10) {
				short count = 0;
				for (int i = 1; i <= num / 10; ++i) {
					answer.push_back('X');
					count++;
				}
				num -= count * 10;
				continue;
			}

			// 9
			if (num / 9) {
				answer.push_back('I');
				answer.push_back('X');
				num -= 9;
				continue;
			}

			// 5
			if (num / 5) {
				answer.push_back('V');
				num -= 5;
				continue;
			}

			// 4
			if (num / 4) {
				answer.push_back('I');
				answer.push_back('V');
				num -= 4;
				continue;
			}

			// 1
			if (num / 1) {
				short count = 0;
				for (int i = 1; i <= num / 1; ++i) {
					answer.push_back('I');
					count++;
				}
				num -= count;
				continue;
			}
		}

		return answer;
	}
};