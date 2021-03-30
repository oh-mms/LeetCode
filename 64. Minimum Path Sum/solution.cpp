class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int x = grid.size();
		int y = grid[0].size();

		for (int i = 1; i < x; ++i)
			grid[i][0] += grid[i - 1][0];

		for (int j = 1; j < y; ++j)
			grid[0][j] += grid[0][j - 1];

		for (int i = 1; i < x; ++i)
			for (int j = 1; j < y; ++j)
				grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);

		return grid[x - 1][y - 1];
	}
};