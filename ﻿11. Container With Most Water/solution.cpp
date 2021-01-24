class Solution {
public:
	int makeArea(vector<int>& height, int lidx, int ridx) {
		int h = (height[lidx] < height[ridx]) ? height[lidx] : height[ridx];
		return (ridx - lidx)*h;
	}

	int maxArea(vector<int>& height) {
		int lIdx = 0, rIdx = height.size() - 1;
		int max = makeArea(height, lIdx, rIdx);
		int tempArea;

		while (lIdx < rIdx) {
			tempArea = makeArea(height, lIdx, rIdx);
			if (max < tempArea)
				max = tempArea;

			if (height[lIdx] < height[rIdx])
				lIdx++;
			else
				rIdx--;
		}

		return max;
	}
};