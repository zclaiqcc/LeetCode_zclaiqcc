/**
* OJ:LeetCode
* Problem: 15. Three Sum
* Author: zclaiqcc
* Blog: zclaicc.github.io
* Github: github.com/zclaiqcc
* Email: zclaiqcc@gmail.com
*/

#ifndef _15_THREESUM_H_
#define _15_THREESUM_H_

#include<vector>
#include<algorithm>

using namespace std; //Shall not using namespaces in .h, bur for ez.

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	//15. Three Sum
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> results;
		int nums_size = nums.size();
		sort(nums.begin(), nums.end());
		for (int begin = 0; begin < nums_size - 1; begin++) {
			//for faster
			if (nums[begin] > 0)
			{
				break;
			}

			//very important lines,it does really matter.
			//to escape the duplication.
			if ((begin > 0) && (nums[begin] == nums[begin - 1]))
				continue;

			//for faster
			//change nums[N] into target and make the sum equals to -nums[N]

			int next = begin + 1;
			int end = nums_size - 1;
			while (next < end) {
				int res = nums[begin] + nums[next] + nums[end];
				if (res > 0) {
					end--;
					while (nums[end] == nums[end + 1])
						end--;
				}
				else if (res < 0) {
					next++;
					while (nums[next] == nums[next] - 1)
						next++;
				}
				else {
					results.push_back(vector<int> { nums[begin], nums[next], nums[end] });
					while (nums[next] == nums[next + 1]) {
						next++;
					}
					while (nums[end] == nums[end - 1]) {
						end--;
					}
					next++;
					end--;
				}
			}
		}
		return results;
	}

};

#endif 