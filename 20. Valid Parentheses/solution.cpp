class Solution {
public:
	bool isValid(string s) {
		stack<char> cStack;

		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
				cStack.push(s[i]);
				continue;
			}

			char c = 0;

			if (cStack.size()) {
				c = cStack.top();
				cStack.pop();
			}

			switch (s[i]) {
			case ')':
				if (c != '(') return false;
				continue;
			case '}':
				if (c != '{') return false;
				continue;
			case ']':
				if (c != '[') return false;
				continue;
			}
		}

		if (cStack.size()) return false;
		return true;
	}
};