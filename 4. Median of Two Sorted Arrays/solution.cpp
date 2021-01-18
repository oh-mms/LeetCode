class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int size = nums1.size() + nums2.size();
		int nums1_idx = 0, nums2_idx = 0;
		vector<int> merged;

		// Insert a smaller element in merged vector.
		// INT_MAX means end of vector.
		if (nums1.size() == 0) nums1.push_back(INT_MAX);
		if (nums2.size() == 0) nums2.push_back(INT_MAX);

		for (int i = 0; i <= size / 2; ++i) {
			if (nums1[nums1_idx] < nums2[nums2_idx]) {
				merged.push_back(nums1[nums1_idx]);
				nums1_idx++;
				if (nums1_idx >= nums1.size()) {
					nums1_idx--;
					nums1[nums1_idx] = INT_MAX;
				}
				continue;
			}

			// Element of nums2 is bigger.
			merged.push_back(nums2[nums2_idx]);
			nums2_idx++;
			if (nums2_idx >= nums2.size()) {
				nums2_idx--;
				nums2[nums2_idx] = INT_MAX;
			}
		}
		
		if (size % 2 == 0) return (merged[merged.size() - 1] + merged[merged.size() - 2]) / 2.0;
		else            return merged[merged.size() - 1];
	}
};