class Solution {
public:
	// Make a string by start-index and end-index, then return it.
	string makeString(string& s, int start, int end) {
		string temp;
		for (int i = start; i <= end; ++i)
			temp.push_back(s[i]);
		return temp;
	}

	// Check that input string is palindrome.
	bool isPalindrome(string& s, int start, int end) {
		if (end - start == 0) {
			return true;
		}

		// even number processing
		if ((end - start + 1) % 2 == 0) {
			int mid = (start + end) / 2 + 1;
			int pre_mid = mid - 1;

			for (int i = 0; i < mid; ++i) {
				if (pre_mid - i >= start && mid + i <= end) {
					if (s[pre_mid - i] != s[mid + i])
						return false;
				}
			}
			return true;
		}

		// odd number processing
		int mid = (start + end) / 2;
		for (int i = 1; i < mid + 1; ++i) {
			if (mid - i >= start && mid + i <= end) {
				if (s[mid - i] != s[mid + i])
					return false;
			}
		}
		return true;
	}

	// Find a longest palindrome substring.
	string longestPalindrome(string s) {
		string answer;
		int sum = 0, count = 0, lidx = 0, ridx = 0;

		// make a pivot sum value.
		for (int i = 0; i < s.size(); ++i)
			if (isPalindrome(s, lidx, i))
				ridx = i;

		for (int i = 0; i <= ridx; ++i) {
			answer.push_back(s[i]);
			sum += s[i];
		}
		ridx++;

		// the next process has to use the value processed before.
		for (int i = 1; i < s.size() - 1; ++i) {
			sum -= s[i - 1]; // use the sum value.
			if (ridx < i) {
				ridx = i;
				sum = 0;
			}

			// ridx is the next index processed before.
			for (int j = ridx; j < s.size(); ++j) {
				sum += s[j];
				count = j - i + 1;

				if (count == 1) continue;

				// even
				if (count % 2 == 0) {
					// if the sum is an even number, the substring can be a palindrome.
					if (sum % 2 == 0) {
						if (!isPalindrome(s, i, j)) continue;
						if (answer.size() < count) {
							answer = makeString(s, i, j);
							ridx = j;
						}
					}
					continue;
				}

				// odd
				int mid = (i + j) / 2;
				int val = sum - s[mid];

				// if the val is an even number, the substring can be a palindrome.
				if (val % 2 == 0) {
					if (!isPalindrome(s, i, j)) continue;
					if (answer.size() < count) { 
						answer = makeString(s, i, j);
						ridx = j;
					}
				}

			}
		}

		return answer;
	}
};