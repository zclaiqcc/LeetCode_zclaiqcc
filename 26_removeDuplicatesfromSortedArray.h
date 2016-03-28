/**
* OJ:LeetCode
* Problem: 26. Remove Duplicates from Sorted Array
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
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() <= 1) {
			return nums.size();
		}
		int i = 0;
		int j = 0;
		while (j < nums.size() - 1) {
			if (nums[j] == nums[j + 1]) {
				j++;
				continue;
			}
			j++;
			i++;
			nums[i] = nums[j];
		}
		return i + 1;
	}
};