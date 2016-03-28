/**
 * OJ:LeetCode
 * Problem: 13. Roman to Integer
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
	int romanToInt(string s) {
		if (s.empty()) {
			return 0;
		}

		vector<int> romanIntMap(24 + 'A');
		romanIntMap['M'] = 1000;
		romanIntMap['D'] = 500;
		romanIntMap['C'] = 100;
		romanIntMap['L'] = 50;
		romanIntMap['X'] = 10;
		romanIntMap['V'] = 5;
		romanIntMap['I'] = 1;

		int sum = romanIntMap[s[s.size() - 1]];

		for (int back = s.size() - 2; back >= 0; back--) {
			if (romanIntMap[s[back]] < romanIntMap[s[back + 1]]) {
				sum -= romanIntMap[s[back]];
			}
			else {
				sum += romanIntMap[s[back]];
			}
		}
		return sum;
	}
};