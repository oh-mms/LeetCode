class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		vector<vector<int>> v; // 문제에서 요구한 2D matrix를 만들지 말라는 조건을 어김.
		for (int i = 0; i < matrix.size(); ++i) { // 열
			vector<int> temp;
			for (int j = matrix.size() - 1; j >= 0; --j) {
				temp.push_back(matrix[j][i]);
			}
			v.push_back(temp);
		}
		matrix = v;
	}
};