#include <string>
#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

string longestCommonPrefix(vector<string>&);

int main() {
	vector<string> test1 = { "flower", "flow", "flight" };
	vector<string> test2 = { "dog", "racecar", "car" };

	string test1Result = longestCommonPrefix(test1);
	cout << "Test1 result: " << test1Result << endl;

	string test2Result = longestCommonPrefix(test2);
	cout << "Test2 result: " << test2Result << endl;
	system("PAUSE");
}

string longestCommonPrefix(vector<string>& strs) {
	// Handle edge case: empty input vector returns empty prefix
	if (strs.empty()) {
		return "";
	}

	int count = 0;
	// Iterate over each character position in the reference string
	for (int j = 0; j < strs[0].size(); j++) {
		// Iterate through each string in the vector
		for (int i = 0; i < strs.size(); i++) {
			// Check if current string is too short or character mismatches
			if (j >= strs[i].size() || strs[0][j] != strs[i][j]) {
				return strs[0].substr(0, count);
			}
		}
		count++;
	}

	return strs[0].substr(0, count);
}