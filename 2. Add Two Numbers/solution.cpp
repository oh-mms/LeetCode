class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* addedNode = nullptr;
		ListNode* curNode = nullptr;
		int sum = 0;

		while (1) {
			// sum carry which is calculated before.
			if (sum >= 10) sum = 1;
			else           sum = 0;

			// if l1, l2 node is not nullptr, then sum each numbers.
			if (l1 != nullptr) {
				sum += l1->val;
				if (l1->next != nullptr) l1 = l1->next;
				else                    l1 = nullptr;
			}

			if (l2 != nullptr) {
				sum += l2->val;
				if (l2->next != nullptr) l2 = l2->next;
				else                    l2 = nullptr;
			}

			// addedNode process.
			ListNode* tempNode = new ListNode;
			tempNode->val = (sum % 10);

			if (addedNode != nullptr) {
				curNode->next = tempNode;
				curNode = tempNode;
			}
			else {
				addedNode = tempNode;
				curNode = addedNode;
			}

			sum -= (sum % 10);

			// end node process.
			if (l1 == nullptr && l2 == nullptr) {
				if (sum >= 10) {
					ListNode* LastNode = new ListNode;
					LastNode->val = 1;
					curNode->next = LastNode;
				}
				break;
			}
		}
		return addedNode;
	}
};