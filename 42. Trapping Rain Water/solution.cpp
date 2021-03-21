class Solution {
public:
	int trap(vector<int>& height) {
		if (height.empty()) return 0;

		int answer = 0;
		int lIdx = 0, rIdx = height.size() - 1;

		vector<int> v(height.size());
		int tempHeight, minHeight = min(height[lIdx], height[rIdx]);

		while (lIdx < rIdx) {
			if (height[lIdx] < minHeight) v[lIdx] = minHeight - height[lIdx];
			if (height[rIdx] < minHeight) v[rIdx] = minHeight - height[rIdx];

			if (height[lIdx] < height[rIdx]) lIdx++;
			else											 rIdx--;

			tempHeight = min(height[lIdx], height[rIdx]);
			minHeight = max(tempHeight, minHeight);
		}

		for (auto& x : v)
			if (x) answer += x;

		return answer;
	}
};