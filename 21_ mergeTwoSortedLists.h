/**
 * OJ:LeetCode
 * Problem: 21. Merge Two Sorted Lists
 * Author: zclaiqcc
 * Blog: zclaicc.github.io
 * Github: github.com/zclaiqcc
 * Email: zclaiqcc@gmail.com
 */
#pragma once

#include<vector>

using namespace std; //Shall not using namespaces in .h, bur for ez.

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
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
};