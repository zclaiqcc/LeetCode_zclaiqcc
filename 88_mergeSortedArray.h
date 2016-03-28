/**
 * OJ:LeetCode
 * Problem: 88. Merge Sorted Array
 * Author: zclaiqcc
 * Blog: zclaicc.github.io
 * Github: github.com/zclaiqcc
 * Email: zclaiqcc@gmail.com
 */

#pragma once

#include<vector>
#include<algorithm>

using namespace std; //Shall not using namespaces in .h, bur for ez.

class Solution {
public:
	//a lazy way to solve the problem :P
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		for (int i = m; i < m + n; i++) {
			nums1[i] = nums2[i - m];
		}
		sort(nums1.begin(), nums1.end());
	}
};