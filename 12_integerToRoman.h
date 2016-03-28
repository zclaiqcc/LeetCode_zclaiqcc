/**
 * OJ:LeetCode
 * Problem: 12. Integer to Roman
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
	string intToRoman(int num) {
		//One number to corresponding Roman 
		string result;
		vector<string> M = { "", "M", "MM", "MMM" };
		vector<string> C = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
		vector<string> X = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
		vector<string> I = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
		result += M[num / 1000];
		result += C[(num % 1000) / 100];
		result += X[(num % 100) / 10];
		result += I[num % 10];
		return result;
	}
};