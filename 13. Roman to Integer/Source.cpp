#include <string>
#include <iostream>

using namespace std;

int romanToInt(string);

int main() {
	string test[4] = { "III", "LVIII", "MCMXCIV", "XIV"};

	for (int i = 0; i < 4; i++) {
		int value = romanToInt(test[i]);
		cout << "Roman Numeral: " << test[i] << ", value: " << value << endl;
	}
	system("PAUSE");
	return 0;
}

int romanToInt(string s) {
	/*
	I        1
	V        5
	X        10
	L        50
	C        100
	D        500
	M        1000

	Six instances of subtraction:
		1. IV	DONE
		2. IX	DONE

		3. XL	DONE
		4. XC	DONE

		5. CD
		6. CM
	*/

	int result = 0;
	int i = 0;
	int strLength = s.length() - 1;

	while (i <= strLength) {
		if (s[i] == 'I') { // check for all possibilities of I
			if (s[i + 1] == 'V') { // check for IV
				result = result + 4;
				i = i + 2;
			}
			else if (s[i + 1] == 'X') { // check for IX
				result = result + 9;
				i = i + 2;
			}
			else {	// check for I
				result = result + 1;
				i = i + 1;
			}
		}
		else if (s[i] == 'V') { // check for V
			result = result + 5;
			i = i + 1;
		}
		else if (s[i] == 'X') { // check for all possibilities of X
			if (s[i + 1] == 'L') { // check for XL
				result = result + 40;
				i = i + 2;
			}
			else if (s[i + 1] == 'C') { // check for XC
				result = result + 90;
				i = i + 2;
			}
			else { // check for X
				result = result + 10;
				i = i + 1;
			}
		}
		else if (s[i] == 'L') { // check for L
			result = result + 50;
			i = i + 1;
		}
		else if (s[i] == 'C') { // check for all C possibilities
			if (s[i + 1] == 'D') { // check for CD
				result = result + 400;
				i = i + 2;
			}
			else if (s[i + 1] == 'M') { // check for CM
				result = result + 900;
				i = i + 2;
			}
			else { // check for C
				result = result + 100;
				i = i + 1;
			}
		}
		else if (s[i] == 'D') { // check for D
			result = result + 500;
			i = i + 1;
		}
		else if (s[i] == 'M') { // check for M
			result = result + 1000;
			i = i + 1;
		}
		// cout << "current value: " << result << endl;
	}
	return result;
}