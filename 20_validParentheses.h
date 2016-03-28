/**
 * OJ:LeetCode
 * Problem: //20. Valid Parentheses
 * Author: zclaiqcc
 * Blog: zclaicc.github.io
 * Github: github.com/zclaiqcc
 * Email: zclaiqcc@gmail.com
 */

#pragma once

#include<vector>
#include<stack>

using namespace std; //Shall not using namespaces in .h, bur for ez.

class Solution {
public:
	//using stack is faster than vector!
	bool isValid(string s) {
		if (s.empty()) {
			return true;
		}
		stack<char> parentheses;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
				parentheses.push(s[i]);
			}
			else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
				if (parentheses.empty()) {
					return false;
				}
				else if ((s[i] == ')' && s[i] != (parentheses.top() + 1)) || ((s[i] == ']' || s[i] == '}') && s[i] != (parentheses.top() + 2))) {
					return false;
				}
				else {
					parentheses.pop();
				}
			}
		}
		return parentheses.empty();
	}
};