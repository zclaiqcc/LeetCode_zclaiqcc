#include<iostream>
#include"Solution.h"

int main() {
	Solution solution;

	ListNode* head = new ListNode(1);
	ListNode* temp = new ListNode(2);
	head->next = temp;
	temp = new ListNode(3);
	head->next->next = temp;
	temp = new ListNode(4);
	head->next->next->next = temp;

	//head = solution.reverseListRecursion(head);

	head = solution.reverseKGroup(head, 2);

	//solution.letterCombinations("69");

	//vector<int> vec{ 6,-18,-20,-7,-15,9,18,10,1,-20,-17,-19,-3,-5,-19,10,6,-11,1,-17,-15,6,17,-18,-3,16,19,-20,-3,-17,-15,-3,12,1,-9,4,1,12,-2,14,4,-4,19,-20,6,0,-19,18,14,1,-15,-5,14,12,-4,0,-10,6,6,-6,20,-8,-6,5,0,3,10,7,-2,17,20,12,19,-13,-1,10,-1,14,0,7,-3,10,14,14,11,0,-4,-15,-8,3,2,-5,9,10,16,-4,-3,-9,-8,-14,10,6,2,-12,-7,-16,-6,10 };
	//cout << solution.threeSumClosest(vec, -52) << endl;
	//string s = "()[]{}";
	//cout << solution.isValid(s);

	//vector<string> strs = { "a","a","b" };
	//cout << solution.longestCommonPrefix(strs) << endl;

	//solution.isMatch("aaa","a*a");
	return 0;
}