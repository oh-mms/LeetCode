class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int sum = nums[0];
		int maxSum = sum;
		for (int i = 1; i < nums.size(); i++) {
			// ��(���� �ε����� ��)���� ���±��� ��ģ ��(�� ����)�� ũ�ٸ�, ��� �̾����.
			// �ƴϸ� ������ �ٽ� ���س����� ����.
			if (sum + nums[i] > nums[i]) sum += nums[i];
			else                        sum = nums[i];
			maxSum = max(maxSum, sum);
		}
		return maxSum;
	}
};