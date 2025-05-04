#include <string>
#include <iostream>
#include <vector>

using namespace std;

bool isValid(string);

int main() {

	string test[] = { "()", "()[]{}", "(]", "([])" };

	for (int i = 0; i < 4; i++) {
		bool result = isValid(test[i]);
		cout << "String: " << test[i] << ", result: " << result << endl;
	}
	system("PAUSE");
}

bool isValid(string s) {

	int pos = 0;
	int lastPos = s.length();
	vector<char> brackets;

	// iterate through string checking each character
	while (pos != lastPos) {
		// if character is an opening bracket push to stack
		if (s[pos] == '(' || s[pos] == '{' || s[pos] == '[') {
			brackets.push_back(s[pos]);
		}

		// if character is a closing bracket
		if (s[pos] == ')' || s[pos] == '}' || s[pos] == ']') {
			// and vector is not empty
			if (!brackets.empty()) {
				// pop from vector if last value in vector matches with current closing bracket
				if (brackets.back() == '(' && s[pos] == ')'){
					brackets.pop_back();
				}
				else if (brackets.back() == '{' && s[pos] == '}'){
					brackets.pop_back();
				}
				else if (brackets.back() == '[' && s[pos] == ']') {
					brackets.pop_back();
				}
				else {
					// return false if current closing bracket doesn't match last value in vector
					return false;
				}
			}
			else {
				// return false if vector array is empty when current closing bracket is found
				return false;
			}
		}
		pos++;
	}

	// if vector is empty string is valid, if not string is not valid
	return brackets.empty();
}