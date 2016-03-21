/**
* OJ:LeetCode
* Problem: 2. Add Two Numbers
* Author: zclaiqcc
* Blog: zclaicc.github.io
* Github: github.com/zclaiqcc
* Contract: zclaiqcc@gmail.com
*/

#ifndef _2_ADDTWONUMBERS_H_
#define _2_ADDTWONUMBERS_H_

#include<vector>

using namespace std; //Shall not using namespaces in .h, bur for ez.

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
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
};

#endif 