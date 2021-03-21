class Solution {
public:
	int jump(vector<int>& nums) {
		int count{ 0 };

		if (nums.size() < 2)
			return count;

		vector<int> DP[10001]; // �ε����� �����ϴ� ����. (���� �� ���� �پ� �Ѿ�� �ϴ� �� count ��)
		DP[0].push_back(0);

		for (int i = 1; i < nums.size(); ++i) {
			count++;
			int maxIdx = -1;
			for (int j = 0; j < DP[i - 1].size(); ++j) {
				// DP[i-1][j] : ������ ����� �ε����� ���ʷ� ������
				int idx = DP[i - 1][j];
				for (int k = 0; k < nums[idx]; ++k) { // �ش� �ε����� �ִ� value�� �̵� ������ ĭ ���� ����
					if (idx + k + 1 < maxIdx - 1) // ���� �ִ� �ε������� ������ ����� �ʿ䰡 ����
						continue;
					DP[i].push_back(idx + k + 1);
					if (idx + k + 1 >= nums.size() - 1)
						return count;
				}
				maxIdx = max(idx + nums[idx], maxIdx); // ���� �ε����� ���� �ִ� �ε������� Ŀ�� �����
			}
		}

		return count;
	}
};