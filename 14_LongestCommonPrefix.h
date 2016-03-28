/**
* OJ:LeetCode
* Problem: 14. Longest Common Prefix
* Author: zclaiqcc
* Blog: zclaicc.github.io
* Github: github.com/zclaiqcc
* Email: zclaiqcc@gmail.com
*/

#pragma once

#include<vector>

using namespace std; //Shall not using namespaces in .h, bur for ez.

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty()) {
			return string();
		}
		for (int i = 0; i < strs[0].size(); i++) {
			for (int j = 0; j < strs.size(); j++) {
				if (i < strs[j].size() && strs[0][i] == strs[j][i]) {
					;
				}
				else
					return strs[0].substr(0, i);
			}
		}
		return strs[0];
	}
};