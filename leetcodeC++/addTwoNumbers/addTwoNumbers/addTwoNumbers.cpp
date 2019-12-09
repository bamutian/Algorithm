// leetcodeC++.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "ListNodeService.h"

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	ListNode * dummy = new ListNode(-1), *cur = dummy;
	int carry = 0;
	while (l1 || l2)
	{
		int val1 = l1 ? l1->val : 0;
		int val2 = l2 ? l2->val : 0;
		int sum = val1 + val2 + carry;
		carry = sum / 10;
		cur->next = new ListNode(sum % 10);
		cur = cur->next;
		if (l1)
		{
			l1 = l1->next;
		}
		if (l2)
		{
			l2 = l2->next;
		}
	}
	if (carry)
	{
		cur->next = new ListNode(1);
	}
	return dummy->next;
}

int _tmain(int argc, _TCHAR* argv[])
{
	
	/*测试 addTwoNumbers*******************/
	ListNodeService list1;
	list1.Insert2List(1);
	list1.Insert2List(2);
	list1.Insert2List(3);
	ListNodeService list2;
	list2.Insert2List(1);
	list2.Insert2List(2);
	list2.Insert2List(3);
	ListNodeService result;
	ListNode *resultHead;
	ListNode *listNodeHead1, *listNodeHead2;
	listNodeHead1 = list1.GetListNode();
	listNodeHead2 = list2.GetListNode();
	resultHead = addTwoNumbers(listNodeHead1, listNodeHead2);
	result.SetListNode(resultHead);
	result.PrintList();
	/*************************************/

	system("pause");
	return 0;
}

