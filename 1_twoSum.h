/** 
* OJ:LeetCode
* Problem: 1_twoSum
* Author: zclaiqcc
* Blog: zclaicc.github.io
* Github: github.com/zclaiqcc
* Contract: zclaiqcc@gmail.com
*/

#ifndef _1_TWOSUM_H_
#define _1_TWOSUM_H_

#include<vector>

using namespace std; //Shall not using namespaces in .h, bur for ez.

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		vector<int> index;
		for (int i = 0; i < nums.size() - 1; i++) {
			for (int j = i + 1; j < nums.size(); j++) {
				if (target == (nums[i] + nums[j])) {
					index.push_back(i + 1);
					index.push_back(j + 1);
					return index;
				}
			}
		}
		return index;
	}
};

#endif 