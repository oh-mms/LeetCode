class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;
		if (x < 10) return true;

		long long revertedVal = 0, tempVal = x;
		while (tempVal >= 1) {
			revertedVal = (revertedVal * 10) + tempVal % 10;
			tempVal /= 10;
		}

		if (x == revertedVal) return true;
		return false;
	}
};