class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* answer = new ListNode;
		ListNode* curNode = answer;

		// Both have nodes.
		while (l1 != nullptr && l2 != nullptr) {
			if (l1->val < l2->val) {
				curNode->next = l1;
				if (l1->next != nullptr) l1 = l1->next;
				else                    l1 = nullptr;
				curNode = curNode->next;
			}
			else {
				curNode->next = l2;
				if (l2->next != nullptr) l2 = l2->next;
				else                    l2 = nullptr;
				curNode = curNode->next;
			}
		}

		// Only l1 has nodes.
		if (l1 != nullptr) {
			while (l1 != nullptr) {
				curNode->next = l1;
				if (l1->next != nullptr) l1 = l1->next;
				else                    l1 = nullptr;
				curNode = curNode->next;
			}
		}

		// Only l2 has nodes.
		if (l2 != nullptr) {
			while (l2 != nullptr) {
				curNode->next = l2;
				if (l2->next != nullptr) l2 = l2->next;
				else                    l2 = nullptr;
				curNode = curNode->next;
			}
		}

		return answer->next;
	}
};