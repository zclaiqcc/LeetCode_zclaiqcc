#ifndef _SOLUTION_H_
#define _SOLUTION_H_

#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string>
#include<stack>

using namespace std; //Shall not using namespaces in .h, bur for ez.

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	//25. Reverse Nodes in k-Group
	//recursion ver.
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (1 == k || nullptr == head) {
			return head;
		}
		int i = 1;
		ListNode* rear = head;
		ListNode* head_temp = new ListNode(0);
		head_temp->next = head;
		ListNode* temp = head;

		while (rear) {
			if (0 == i % k) {
				rear = rear->next;
				if (1 == i / k) {
					head = reverseListRecursionWithSomeSmallChanges(head_temp->next, rear);
					head_temp = head_temp->next;
					head_temp->next = rear;
				}
				else {
					temp = head_temp->next;
					head_temp->next = reverseListRecursionWithSomeSmallChanges(head_temp->next, rear);
					temp->next = rear;
					head_temp = temp;
				}
				i++;
			}
			else {
				rear = rear->next;
				i++;
			}
		}
		return head;
	}

	//reverse a list with recursion.
	ListNode* reverseListRecursionWithSomeSmallChanges(ListNode* head, ListNode* rear) {
		if (rear == head->next) { //if (nullptr == head->next)
			return head;
		}

		ListNode* head_new = reverseListRecursionWithSomeSmallChanges(head->next, rear);
		head->next->next = head;
		head->next = nullptr;
		return head_new;
	}

	//reverse a list with recursion.
	ListNode* reverseListRecursion(ListNode* head) {
		//I couldn't figure out why so many bolgs would use if(nullptr == head || nullptr == head->next). 
		//One step at once, so nullptr == head would never be true cuz the last recursion has passed when nullptr == head->next. 
		//Stupid
		if (nullptr == head->next) {
			return head;
		}

		ListNode* head_new = reverseList(head->next);
		head->next->next = head;
		head->next = nullptr;
		return head_new;
	}

	//ListNode* reverseKGroup(ListNode* head, int k) {
	//	if (1 == k || head == nullptr) {
	//		return head;
	//	}
	//	ListNode* head_temp = new ListNode(0);
	//	head_temp->next = head;//the virtual head of every part of list
	//	ListNode* first = head;//the very first one of every part of list(in fact it always be the last node of each part)
	//	ListNode* second = head->next;// the node that would be the new first node of the part.
	//	ListNode* third = head->next;// third node will move at the beginning of loop
	//	ListNode* rear = head;
	//	int i = 1;
	//	while (rear) {
	//		if (0 == i % k) {
	//			rear = rear->next;
	//			while (third != rear) {
	//				third = third->next;

	//				second->next = head_temp->next;
	//				first->next = third;
	//				head_temp->next = second;
	//				second = first->next;
	//			}
	//			if (1 == i / k) {
	//				head = head_temp->next;
	//			}
	//			if (rear) {
	//				head_temp = first;
	//				first = rear;
	//				second = third = rear->next;
	//			}

	//			i++;
	//		}
	//		else {
	//			rear = rear->next;
	//			i++;
	//		}
	//	}

	//	return head;
	//}

	//22. Generate Parentheses
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		//m is initialized as 0.
		addingpar(res, "", n, 0);
		return res;
	}
	//n means the left parentheses, m means the right ones.
	void addingpar(vector<string> &v, string str, int n, int m) {
		if (n == 0 && m == 0) {
			v.push_back(str);
			return;
		}
		if (m > 0) { addingpar(v, str + ")", n, m - 1); }
		if (n > 0) { addingpar(v, str + "(", n - 1, m + 1); }
	}

	//17. Letter Combinations of a Phone Number
	vector<string> letterCombinations(string digits) {
		vector<string> map{ {}, {},{ "abc" },{ "def" },{ "ghi" },{ "jkl" },{ "mno" },{ "pqrs" },{ "tuv" },{ "wxyz" } };
		vector<string> result;
		if (digits.size() < 1) {
			return result;
		}
		result.push_back("");

		int digits_size = digits.size();
		for (int i = 0; i < digits_size; i++) {
			vector<string> temp;
			int map_size = map[digits[i] - '0'].size();
			for (int j = 0; j < map_size; j++) {
				int result_size = result.size();
				for (int k = 0; k < result_size; k++) {
					temp.push_back(result[k] + map[digits[i] - '0'][j]);
				}
			}
			result = temp;
		}

		return result;
	}

	//16. 3SumClosest
	int threeSumClosest(vector<int>& nums, int target) {
		int nums_size = nums.size();
		sort(nums.begin(), nums.end());
		int min = nums[0] + nums[1] + nums[2];
		for (int begin = 0; begin + 2 < nums_size; begin++) {

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
				if (res > target) {
					if (abs(min - target) > abs(res - target)) {
						min = res;
					}
					end--;
					while (nums[end] == nums[end + 1])
						end--;
				}
				else if (res < target) {
					if (abs(min - target) > abs(res - target)) {
						min = res;
					}
					next++;
					while (nums[next] == nums[next] - 1)
						next++;

				}
				else {
					return target;
				}
			}
		}
		return min;
	}

	//4. Median of Two Sorted Arrays
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.size() > nums2.size()) {
			vector<int> temp = nums1;
			nums1 = nums2;
			nums2 = temp;
		}

		if (nums1.empty()) {
			if (1 == nums2.size() % 2) {
				return nums2[nums2.size() / 2];
			}
			else return (nums2[nums2.size() / 2 - 1] + nums2[nums2.size() / 2]) / 2.0;
		}

		int min = 0;
		int max = nums1.size();
		int left = 0;
		int right = 0;

		while (min < max) {
			int i = (max - min) / 2;
			int j = (nums1.size() + nums2.size() + 1) / 2 - i;
			if (i > 0 && j < nums2.size() && nums1[i - 1] > nums2[j]) {
				max = i - 1;
			}
			else if (i < nums1.size() && j > 0 && nums1[i] < nums2[j]) {
				min = i + 1;
			}
			else {
				if (i == 0) {
					left = nums2[j - 1];
				}
				else if (j == 0) {
					left = nums1[i - 1];
				}
				else {
					left = std::max(nums1[i - 1], nums2[j -1]);
				}

				if (1 == nums2.size() % 2) {
					return left;
				}

				if (i == nums1.size()) {
					right = nums2[j];
				}
				else if (j == nums2.size()) {
					right = nums1[i];
				}
				else {
					right = std::min(nums1[i], nums2[j]);
				}
				return (left + right) / 2.0;
			}
		}
	}

	//26. Remove Duplicates from Sorted Array
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

	//88. Merge Sorted Array
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		for (int i = m; i < m + n; i++) {
			nums1[i] = nums2[i - m];
		}
		sort(nums1.begin(), nums1.end());
	}

	//21. Merge Two Sorted Lists
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (nullptr == l1) {
			return l2;
		}
		if (nullptr == l2) {
			return l1;
		}

		ListNode* head, *cur = head;
		if (l1->val < l2->val) {
			head = l1;
		}
		else {
			head = l2;
		}

		while (l1 != nullptr && l2 != nullptr) {
			if (l1->val < l2->val) {
				cur->next = l1;
				cur = cur->next;
				l1 = l1->next;
			}
			else {
				cur->next = l2;
				cur = cur->next;
				l2 = l2->next;
			}
		}

		if (nullptr == l1) {
			cur->next = l2;
			return head;
		}
		else {
			cur->next = l1;
			return head;
		}
	}

	//20. Valid Parentheses
	//using stack is faster than vector!
	bool isValid(string s) {
		if (s.empty()) {
			return true;
		}
		stack<char> parentheses;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
				parentheses.push(s[i]);
			}
			else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
				if (parentheses.empty()) {
					return false;
				}
				else if ((s[i] == ')' && s[i] != (parentheses.top() + 1)) || ((s[i] == ']' || s[i] == '}') && s[i] != (parentheses.top() + 2))) {
					return false;
				}
				else {
					parentheses.pop();
				}
			}
		}
		return parentheses.empty();
	}

	//14. Longest Common Prefix
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.empty()) {
			return string();
		}
		for (int i = 0; i < strs[0].size(); i++) {
			for (int j = 0; j < strs.size(); j++) {
				if (i < strs[j].size() && strs[0][i] == strs[j][i]) {
					;
				}
				else
					return strs[0].substr(0, i);
			}
		}
		return strs[0];
	}

	//string longestCommonPrefix(vector<string>& strs) {
	//	if (strs.empty()) {
	//		return string();
	//	}
	//	for (int i = 0; i < strs[0].size();i ++) {
	//		for (int j = 1; j < strs.size() * 2;j *= 2) {
	//			for (int k = 0; k < j && k + j< strs.size(); k++) {
	//				if (i < strs[k].size() && i < strs[k + j].size() && strs[k][i] == strs[k + j][i]) {
	//					;
	//				}
	//				else return strs[k].substr(0, i);
	//			}
	//		}
	//	}
	//	return strs[0];
	//}

	//11. Container With Most Water
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

	//13. Roman to Integer
	//with vector
	int romanToInt(string s) {
		if (s.empty()) {
			return 0;
		}

		vector<int> romanIntMap(24 + 'A');
		romanIntMap['M'] = 1000;
		romanIntMap['D'] = 500;
		romanIntMap['C'] = 100;
		romanIntMap['L'] = 50;
		romanIntMap['X'] = 10;
		romanIntMap['V'] = 5;
		romanIntMap['I'] = 1;

		int sum = romanIntMap[s[s.size() - 1]];

		for (int back = s.size() - 2; back >= 0; back--) {
			if (romanIntMap[s[back]] < romanIntMap[s[back + 1]]) {
				sum -= romanIntMap[s[back]];
			}
			else {
				sum += romanIntMap[s[back]];
			}
		}
		return sum;
	}

	//with map
	//int romanToInt(string s) {
	//	if (s.empty()) {
	//		return 0;
	//	}

	//	unordered_map<char, int> romanIntMap = { { 'M' , 1000 },
	//											 { 'D' , 500 },
	//											 { 'C' , 100 },
	//											 { 'L' , 50 },
	//											 { 'X' , 10 },
	//											 { 'V' , 5 },
	//											 { 'I' , 1 } };
	//	int sum = romanIntMap[s[s.size() - 1]];
	//	for (int back = s.size() - 2; end >= 0; end--) {
	//		if (romanIntMap[s[back]] < romanIntMap[s[back + 1]]) {
	//			sum -= romanIntMap[s[back]];
	//		}
	//		else {
	//			sum += romanIntMap[s[back]];
	//		}
	//	}
	//	return sum;
	//}

	//12. Integer to Roman
	string intToRoman(int num) {
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

	//10. Regular Expression Matching
	//recursion solution
	//bool isMatch(string s, string p) {
	//	if (p.empty())
	//		return s.empty();

	//	if ('*' == p[1])
	//		return (isMatch(s, p.substr(2)) || !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p));
	//	else
	//		return !s.empty() && (s[0] == p[0] || '.' == p[0]) && isMatch(s.substr(1), p.substr(1));
	//}

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

		f[0][0] = true;
		// p[0.., j - 3, j - 2, j - 1] matches empty iff p[j - 1] is '*' and p[0..j - 3] matches empty
		for (int j = 1; j <= n; j++)
			//f[0][j] = j > 1 && '*' == p[j - 1] && f[0][j - 2];
			f[0][j] = j > 1 && f[0][j - 2] && '*' == p[j - 1];

		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
				if (p[j - 1] != '*')
					f[i][j] = f[i - 1][j - 1] && (s[i - 1] == p[j - 1] || '.' == p[j - 1]);
				else
					// p[0] cannot be '*' so no need to check "j > 1" here
					f[i][j] = f[i][j - 2] || (s[i - 1] == p[j - 2] || '.' == p[j - 2]) && f[i - 1][j];

		return f[m][n];
	}
	
	//1. Two Sum
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

	//2. Add Two Numbers
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if (nullptr == l1) {
			return l2;
		}
		else if (nullptr == l2) {
			return l1;
		}

		//use l1 as the sum_List
		ListNode* sum = l1;
		int flag = 0;
		while (1) {
			l1->val = l1->val + l2->val + flag;
			if (l1->val >= 10) {
				l1->val %= 10;
				flag = 1;
			}
			else {
				flag = 0;
			}

			if (nullptr == l1->next && nullptr == l2->next) {
				if (1 == flag) {
					l1->next = new ListNode(1);
				}
				return sum;
			}
			else if (nullptr == l1->next || nullptr == l2->next) {
				if (nullptr == l1->next) {
					l1->next = l2->next;
				}
				if (1 == flag) {
					l1 = l1->next;
					while (1) {
						l1->val += flag;
						if (l1->val >= 10) {
							l1->val = 0;
							flag = 1;
						}
						else {
							flag = 0;
						}
						if (nullptr == l1->next) {
							if (1 == flag) {
								l1->next = new ListNode(1);
							}
							return sum;
						}
						l1 = l1->next;
					}
				}
				return sum;
			}
			l1 = l1->next;
			l2 = l2->next;
		}
	}

	//3. Longest Substring Without Repeation Characters
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

	//5. Longest Palindromic Substring
	string longestPalindrome(string s) {
		if (s.size() <= 1) {
			return s;
		}

		int front = 0;
		int len = 1;

		for (int cur = 0; cur < s.size(); cur++) {
			int front_cur = cur == 0 ? 0 : cur - 1;
			int end_cur = cur + 1;
			while (end_cur < s.size() && s[cur] == s[end_cur]) {
				end_cur++;
				if (len < end_cur - cur) {
					front = cur;
					len = end_cur - cur;
				}
			}

			cur = end_cur - 1;

			for (; front_cur >= 0 && end_cur < s.size() && s[front_cur] == s[end_cur]; front_cur--, end_cur++) {
				if (len < end_cur - front_cur + 1) {
					front = front_cur;
					len = end_cur - front_cur + 1;
				}
			}
		}
		return string(s.begin() + front, s.begin() + front + len);
	}

	//6. ZigZag Conversion
	string convert(string s, int numRows) {
		string s_result = "";
		int cur_loc = 0;
		int s_size = s.size();
		if (1 == numRows || numRows >= s_size) {
			return s;
		}
		int i = 1;
		int j = 1;

		for (; (cur_loc = 2 * (numRows - 1) * (j - 1)) < s_size; j++) {
			s_result += s[cur_loc];
		}

		i++;
		for (; i < numRows; i++) {
			for (j = 1; (cur_loc = i - 1 + 2 * (numRows - 1) * (j - 1)) < s_size; j++) {
				s_result += s[cur_loc];
				if ((cur_loc + 2 * numRows - 2 * i) < s_size)
					s_result += s[cur_loc + 2 * numRows - 2 * i];
			}
		}

		for (j = 1; (cur_loc = i - 1 + 2 * (numRows - 1) * (j - 1)) < s_size; j++) {
			s_result += s[cur_loc];
		}
		return s_result;
	}

	//7. Reverse Integer
	int reverse(int x) {
		if (0 == x) {
			return 0;
		}
		long long x_long = x;
		int symbol = 1;
		if (x_long < 0) {
			symbol = -1;
			x_long = -x_long;
		}

		long long int result = 0;
		long long int x_temp = x_long;
		while (x_temp) {
			x_temp = x_temp / 10 * 10;
			result = x_long - x_temp + result * 10;
			x_temp /= 10;
			x_long /= 10;
		}
		if (result > 2147483646 || result < -2147483647) {
			return 0;
		}
		return (int)result * symbol;
	}

	//8. String to Integer (atoi)
	int myAtoi(string str) {
		int str_len = str.size();
		if (0 == str_len) {
			return 0;
		}

		int cur_loc = 0;
		char c = 0;
		int symbol = 1;
		long long int long_result = 0;

		while (cur_loc < str_len) {
			c = str[cur_loc];
			if (c == '-') {
				symbol = -1;
				cur_loc++;
				break;
			}
			else if (c == '+') {
				cur_loc++;
				break;
			}
			else if (c <= '9' && c >= '0') {
				break;
			}
			else if (c == ' ') {
				cur_loc++;
			}
			else {
				return 0;
			}
		}

		for (; cur_loc < str_len; cur_loc++) {
			if ((c = str[cur_loc]) <= '9' && c >= '0') {
				long_result = long_result * 10 + (c - '0');
				if (long_result * symbol > INT_MAX) {
					return INT_MAX;
				}
				else if (long_result * symbol < INT_MIN) {
					return INT_MIN;
				}
			}
			else {
				break;
			}
		}

		return (int)long_result * symbol;
	}
	
	//9. Palindrome Number
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

	//15. 3Sum
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

	//18. 4Sum
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> results;
		int nums_size = nums.size();
		for (int first = 0; first < nums_size; first++) {
			if (first > 0 && nums[first] == nums[first - 1]) {
				continue;
			}
			if (nums[first] + nums[first + 1] + nums[first + 2] + nums[first + 3] > target) break;
			if (nums[first] + nums[nums_size - 3] + nums[nums_size - 2] + nums[nums_size - 1] < target) continue;

			for (int second = first + 1; second < nums_size; second++) {
				if (second > first + 1 && nums[second] == nums[second - 1]) {
					continue;
				}
				if (nums[first] + nums[second] + nums[second + 1] + nums[second + 2] > target) break;
				if (nums[first] + nums[second] + nums[nums_size - 2] + nums[nums_size - 1] < target) continue;

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

	//19. Remove Nth Node From End of List
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head->next == NULL) {
			return NULL;
		}

		ListNode* front = head;
		ListNode* end = head;
		ListNode* before = head;

		for (int i = 0; i < n; i++) {
			end = end->next;
		}

		while (end != NULL) {
			before = front;
			front = front->next;
			end = end->next;
		}
		if (before == front) {
			head = head->next;
		}
		else {
			before->next = front->next;
		}
		return head;
	}

	//234. Palindrome Linked List
	bool isPalindrome(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return true;
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast->next != NULL && fast->next->next != NULL) {
			slow = slow->next;
			fast = fast->next->next;
		}
		slow->next = reverseList(slow->next);
		slow = slow->next;
		while (slow != NULL) {
			if (head->val != slow->val)
				return false;
			head = head->next;
			slow = slow->next;
		}
		return true;
	}
	ListNode* reverseList(ListNode* head) {
		ListNode* pre = NULL;
		ListNode* next = NULL;
		while (head != NULL) {
			next = head->next;
			head->next = pre;
			pre = head;
			head = next;
		}
		return pre;
	}
};

#endif