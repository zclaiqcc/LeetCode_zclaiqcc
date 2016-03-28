/**
 * OJ:LeetCode
 * Problem: 5. Longest Palindromic Substring
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
	//Search for the middle pole of the palindrome
	string longestPalindrome(string s) {
		if (s.size() <= 1) {
			return s;
		}

		int front = 0;
		int len = 1;

		for (int cur = 0; cur < s.size(); cur++) {
			int front_cur = cur == 0 ? 0 : cur - 1;
			int end_cur = cur + 1;

			//jump the same characters, cuz they are combined as one character.
			while (end_cur < s.size() && s[cur] == s[end_cur]) {
				end_cur++;
				if (len < end_cur - cur) {
					front = cur;
					len = end_cur - cur;
				}
			}

			cur = end_cur - 1;

			//to judge if cur is longest substring when being the middle pole.
			for (; front_cur >= 0 && end_cur < s.size() && s[front_cur] == s[end_cur]; front_cur--, end_cur++) {
				if (len < end_cur - front_cur + 1) {
					front = front_cur;
					len = end_cur - front_cur + 1;
				}
			}
		}
		return string(s.begin() + front, s.begin() + front + len);
	}
};