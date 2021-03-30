class Solution {
public:
	int climbStairs(int n) {
		// DP[n] = DP[n-1] + DP[n-2];
		int* DP = new int[n + 1];
		DP[1] = 1;
		if (n > 1) DP[2] = 2;
		for (int i = 3; i < n + 1; ++i)
			DP[i] = DP[i - 1] + DP[i - 2];
		return DP[n];
	}
};