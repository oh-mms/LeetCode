class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == nullptr)
			return head;

		ListNode* cur = head;
		int count = 1;
		while (cur->next != nullptr) {
			cur = cur->next;
			count++;
		}

		// Delete 1st Node.
		if (count == n) {
			cur = head->next;
			delete head;
			return cur;
		}

		cur = head;
		ListNode* fore = nullptr;

		for (int idx = 0; idx < count - n; ++idx) {
			fore = cur;
			cur = cur->next;
		}

		if (fore != nullptr)
			fore->next = cur->next;
		if (cur != nullptr)
			delete cur;
		return head;
	}
};