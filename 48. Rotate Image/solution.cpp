class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		vector<vector<int>> v; // �������� �䱸�� 2D matrix�� ������ ����� ������ ���.
		for (int i = 0; i < matrix.size(); ++i) { // ��
			vector<int> temp;
			for (int j = matrix.size() - 1; j >= 0; --j) {
				temp.push_back(matrix[j][i]);
			}
			v.push_back(temp);
		}
		matrix = v;
	}
};