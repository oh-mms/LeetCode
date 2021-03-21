class Solution {
public:
	int jump(vector<int>& nums) {
		int count{ 0 };

		if (nums.size() < 2)
			return count;

		vector<int> DP[10001]; // 인덱스를 저장하는 슬롯. (행은 몇 번을 뛰어 넘어야 하는 지 count 수)
		DP[0].push_back(0);

		for (int i = 1; i < nums.size(); ++i) {
			count++;
			int maxIdx = -1;
			for (int j = 0; j < DP[i - 1].size(); ++j) {
				// DP[i-1][j] : 이전에 저장된 인덱스를 차례로 가져옴
				int idx = DP[i - 1][j];
				for (int k = 0; k < nums[idx]; ++k) { // 해당 인덱스에 있는 value로 이동 가능한 칸 수를 정함
					if (idx + k + 1 < maxIdx - 1) // 이전 최대 인덱스보다 작으면 계산할 필요가 없음
						continue;
					DP[i].push_back(idx + k + 1);
					if (idx + k + 1 >= nums.size() - 1)
						return count;
				}
				maxIdx = max(idx + nums[idx], maxIdx); // 다음 인덱스는 현재 최대 인덱스보다 커야 계산함
			}
		}

		return count;
	}
};