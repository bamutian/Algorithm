#include "stdafx.h"
#include "Test.h"


Test::Test()
{
}


Test::~Test()
{
}

void Test::TestAddTwoNumbers()
{

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
	resultHead = Solution::addTwoNumbers(listNodeHead1, listNodeHead2);
	result.SetListNode(resultHead);
	result.PrintList();
}
