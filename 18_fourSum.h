/**
* OJ:LeetCode
* Problem: 18. Four Sum
* Author: zclaiqcc
* Blog: zclaicc.github.io
* Github: github.com/zclaiqcc
* Contract: zclaiqcc@gmail.com
*/

#ifndef _18_FOURSUM_H_
#define _18_FOURSUM_H_

#include<vector>
#include<algorithm>

using namespace std; //Shall not using namespaces in .h, bur for ez.

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> results;
		int nums_size = nums.size();
		for (int first = 0; first < nums_size; first++) {
			if (first > 0 && nums[first] == nums[first - 1]) {
				continue;
			}
			if (nums[first] + nums[first + 1] + nums[first + 2] + nums[first + 3]>target) break;
			if (nums[first] + nums[nums_size - 3] + nums[nums_size - 2] + nums[nums_size - 1]<target) continue;

			for (int second = first + 1; second < nums_size; second++) {
				if (second > first + 1 && nums[second] == nums[second - 1]) {
					continue;
				}
				if (nums[first] + nums[second] + nums[second + 1] + nums[second + 2]>target) break;
				if (nums[first] + nums[second] + nums[nums_size - 2] + nums[nums_size - 1]<target) continue;

				int third = second + 1;
				int fourth = nums_size - 1;
				int res = 0;
				while (third < fourth) {
					res = nums[first] + nums[second] + nums[third] + nums[fourth];
					if (res > target) {
						fourth--;
						while (nums[fourth] == nums[fourth + 1]) {
							fourth--;
						}
					}
					else if (res < target) {
						third++;
						while (nums[third] == nums[third - 1]) {
							third++;
						}
					}
					else {
						results.push_back(vector<int> { nums[first], nums[second], nums[third], nums[fourth] });
						while (third < nums_size - 1 && nums[third] == nums[third + 1]) {
							third++;
						}
						while (fourth > 1 && nums[fourth] == nums[fourth - 1]) {
							fourth--;
						}
						third++;
						fourth--;
					}
				}
			}
		}
		return results;
	}
};

#endif 