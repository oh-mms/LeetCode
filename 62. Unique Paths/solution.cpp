class Solution {
public:
	int uniquePaths(int m, int n) {
		int** grid = new int*[m];
		for (int i = 0; i < m; ++i)
			grid[i] = new int[n];

		// 첫 행과 첫 열만 1로 채움.
		for (int i = 0; i < m; ++i) grid[i][0] = 1;
		for (int i = 0; i < n; ++i) grid[0][i] = 1;

		// 규칙상 다음 칸은 이 전 두 방향의 칸의 합으로 이루어짐.
		for (int i = 1; i < m; ++i)
			for (int j = 1; j < n; ++j)
				grid[i][j] = grid[i][j - 1] + grid[i - 1][j];

		return grid[m - 1][n - 1];
	}
};