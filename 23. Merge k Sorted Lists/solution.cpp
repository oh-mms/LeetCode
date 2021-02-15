class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		int buckets[20001]; // Solve using Counting Sort.
		for (int i = 0; i < 20001; ++i)
			buckets[i] = 0;

		bool flag = false;
		for (int i = 0; i < lists.size(); ++i) {
			ListNode* s = lists[i];
			while (s != nullptr) {
				flag = true;
				buckets[s->val + 10000]++;
				s = s->next;
			}
		}

		if (!flag) return nullptr;

		ListNode* l = new ListNode;
		ListNode* curNode = l;
		for (int i = 0; i < 20001; ++i) {
			if (!buckets[i])
				continue;
			for (int j = 0; j < buckets[i]; ++j) {
				curNode->next = new ListNode(i - 10000);;
				curNode = curNode->next;
			}
		}

		return l->next;
	}
};