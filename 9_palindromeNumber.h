/**
 * OJ:LeetCode
 * Problem: 9. Palindrome Number
 * Author: zclaiqcc
 * Blog: zclaicc.github.io
 * Github: github.com/zclaiqcc
 * Email: zclaiqcc@gmail.com
 */

#ifndef _9_PALINFROMENUMBER_H_
#define _9_PALINFROMENUMBER_H_

class Solution {
public:
	bool isPalindrome(int x) {
		if (x == 0) {
			return true;
		}

		if (x < 0 || x % 10 == 0) {
			return false;
		}

		int x_ori = x;
		int x_rev = 0;
		while (x != 0) {
			x_rev = x_rev * 10 + x % 10;
			x /= 10;
		}
		return x_rev == x_ori;
	}
};

#endif 