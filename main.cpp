#include<iostream>
#include"Solution.h"

int main() {
	Solution solution;

	string s = "()[]{}";
	cout << solution.isValid(s);

	//vector<string> strs = { "a","a","b" };
	//cout << solution.longestCommonPrefix(strs) << endl;

	//solution.isMatch("aaa","a*a");
	return 0;
}