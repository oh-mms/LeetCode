class Solution {
public:
	int reverse(int x) {
		if (x == 0)
			return 0;

		long long temp = x;
		bool isMinus = false;

		if (temp < 0) {
			isMinus = true;
			temp *= -1;
		}

		short val[10];
		for (int i = 0; i < 10; ++i)
			val[i] = -1;

		long long reversed = 0;

		for (int i = 0; i < 10; ++i) {
			if (temp / 10) {
				val[i] = temp % 10;
				temp /= 10;
			}
			else {
				val[i] = temp;
				break;
			}
		}

		reversed += val[0];

		for (int i = 1; i < 10; ++i) {
			if (val[i] != -1) {
				reversed *= 10;
				reversed += val[i];
			}
		}

		if (isMinus)
			reversed *= -1;

		if (reversed > INT_MAX)
			return 0;

		if (reversed < INT_MIN)
			return 0;

		return reversed;
	}
};