class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int sum = nums[0];
		int maxSum = sum;
		for (int i = 1; i < nums.size(); i++) {
			// 나(현재 인덱스의 값)보다 여태까지 합친 것(나 포함)이 크다면, 계속 이어붙임.
			// 아니면 나부터 다시 더해나가게 시작.
			if (sum + nums[i] > nums[i]) sum += nums[i];
			else                        sum = nums[i];
			maxSum = max(maxSum, sum);
		}
		return maxSum;
	}
};