/**
* OJ:LeetCode
* Problem: 10. Regular Expression Matching
* Author: zclaiqcc
* Blog: zclaicc.github.io
* Github: github.com/zclaiqcc
* Contract: zclaiqcc@gmail.com
*/

#ifndef _10_REGULAREXPRESSIONMATCHIN_H_
#define _10_REGULAREXPRESSIONMATCHIN_H_

#include<vector>

using namespace std; //Shall not using namespaces in .h, bur for ez here.

class Solution {
public:
	//recursion solution
	bool isMatch(string s, string p) {
		if (p.empty())
			return s.empty();

		if ('*' == p[1])
			return (isMatch(s, p.substr(2)) || !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p));
		else
			return !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p.substr(1));
	}

	//DP (as for dynamic programming) solution
	bool isMatch(string s, string p) {
		/**
		* f[i][j]: if s[0..i-1] matches p[0..j-1]
		* if p[j - 1] != '*'
		*      f[i][j] = f[i - 1][j - 1] && s[i - 1] == p[j - 1]
		* if p[j - 1] == '*', denote p[j - 2] with x
		*      f[i][j] is true iff any of the following is true
		*      1) "x*" repeats 0 time and matches empty: f[i][j - 2]
		*      2) "x*" repeats >= 1 times and matches "x*x": s[i - 1] == x && f[i - 1][j]
		* '.' matches any single character
		*/
		int m = s.size(), n = p.size();
		vector<vector<bool>> f(m + 1, vector<bool>(n + 1, false));

		//here i remove an assignment cuz i think it's not necessary

		f[0][0] = true;
		// p[0.., j - 3, j - 2, j - 1] matches empty iff p[j - 1] is '*' and p[0..j - 3] matches empty
		for (int j = 1; j <= n; j++)
			//f[0][j] = j > 1 && '*' == p[j - 1] && f[0][j - 2];
			//explaination is below.
			f[0][j] = j > 1 && f[0][j - 2] && '*' == p[j - 1];

		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				if (p[j - 1] != '*')
					f[i][j] = f[i - 1][j - 1] && (s[i - 1] == p[j - 1] || '.' == p[j - 1]);
				else
					//&& > || 
					//f[i][j - 2]: to deal with x* in 0 time
					//f[i - 1][j]: to escape x once.
					//(s[i - 1] == p[j - 2] || '.' == p[j - 2]) && f[i - 1][j]: e.g.(ba-a*)(aa-a*)
					// p[0] cannot be '*' so no need to check "j > 1" here.(the rule of regular expression)
					f[i][j] = f[i][j - 2] || (s[i - 1] == p[j - 2] || '.' == p[j - 2]) && f[i - 1][j];
		return f[m][n];
	}
};

#endif 