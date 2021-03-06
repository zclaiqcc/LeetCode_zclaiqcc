/**
* OJ:LeetCode
* Problem: 3. Longest Substring Without Repeation Characters
* Author: zclaiqcc
* Blog: zclaicc.github.io
* Github: github.com/zclaiqcc
* Email: zclaiqcc@gmail.com
*/

#ifndef _3_LONGESTSUBSTRINGWITHOUTREPEATIONCHARACTERS_H_
#define _3_LONGESTSUBSTRINGWITHOUTREPEATIONCHARACTERS_H_

#include"Solution.h"
#include<vector>
#include<algorithm>

using namespace std; //Shall not using namespaces in .h, bur for ez.

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		vector<int> flag(256, -1);
		int start = 0, longest = 0;
		for (int i = 0; i != s.size(); ++i) {
			//flag[s[i]] + 1 means the last location of s[i], 0 means haven't exist before
			start = max(start, flag[s[i]] + 1);
			flag[s[i]] = i;
			longest = max(longest, i - start + 1);
		}
		return longest;
	}
};

#endif 