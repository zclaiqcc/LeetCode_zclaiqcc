/**
 * OJ:LeetCode
 * Problem: 11. Container With Most Water
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
	//start from the wildest condition, then the lower height between them will never be the max area
	//narrow the width and stop when meeting a higher height, compare the higher but narrower condition to the previous one.
	int maxArea(vector<int>& height) {
		int front = 0;
		int end = height.size() - 1;
		int max_area = 0;
		while (front < end) {
			int h = min(height[front], height[end]);
			max_area = max(max_area, (end - front) * h);
			while (height[front] <= h && front < end) {
				front++;
			}
			while (height[end] <= h && front < end) {
				end--;
			}
		}
		return max_area;
	}
};