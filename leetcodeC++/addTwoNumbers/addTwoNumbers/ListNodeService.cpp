#include "stdafx.h"
#include "ListNodeService.h"


ListNodeService::ListNodeService()
{
	// 创建链表
	CreateList();
}


ListNodeService::~ListNodeService()
{
	// 清除链表
	ClearList();
}


//创建头结点
void ListNodeService::CreateList()
{
	head = new ListNode(0);
}
//从头插入一个节点
void ListNodeService::Insert2List(const int& d)
{
	ListNode *p = new ListNode(d);
	p->next = head->next;
	head->next = p;
}
//打印函数
void ListNodeService::PrintList()
{
	for (ListNode * p = head->next; p; p = p->next){
		cout << p->val << endl;
	}
}
//在d位置之前插入d1
void ListNodeService::InsertByPos(const int& d, const int& d1)
{
	ListNode * p = FindListByData(d);
	ListNode * q = new ListNode(d1);
	q->next = p->next;
	p->next = q;
}

//删除
void ListNodeService::EraseByData(const int& d)
{
	ListNode * p = FindListByData(d);
	//因为p是上一个节点的位置，用q来保存
	//要删除的节点的地址
	ListNode *q = p->next;
	//通过将上一个节点的next指针指向要删除节点的next指
	//针志向的节点实现断开要删除节点的目的
	p->next = p->next->next;
	//删除要删除的节点q
	delete q;
}

//修改指定数据
void ListNodeService::UpdataByData(const int& d, const int& d1)
{
	ListNode * p = FindListByData(d);
	p->next->val = d1;
}

//反转链表
void ListNodeService::ReverseList()
{
	ListNode * p = head->next;//头结点之后的第1个节点
	ListNode * q = head->next->next;//头结点之后的第2节点
	ListNode * m = head->next->next->next;//头结点之后的第3个节点
	p->next = NULL;//将头接点之后的第1个节点的next指针置为空
	//根据m是否为空来判断 以此逆序每一个节点
	while (m){
		q->next = p;
		p = q;
		q = m;
		m = m->next;
	}
	//将最后一个节点逆序
	q->next = p;
	//将头从新指向新的的第1个节点(之前的最后一个节点)
	head->next = q;
}

//清理链表函数
void  ListNodeService::ClearList(){
	ListNode * p = head;
	//从头节点开始循环删除
	while (p){
		ListNode * q = p->next;
		delete p;
		p = q;
	}
}
//查找数据d的上一个节点位置的函数
//为了方便后面删除操作
ListNode* ListNodeService::FindListByData(const int& d){
	ListNode * p = head;
	for (; p; p = p->next){
		if (p->next->val == d)
			break;
	}
	return p;
}


ListNode* ListNodeService::GetListNode()
{
	return this->head;
}

void ListNodeService::SetListNode(ListNode* node)
{

	head = node;
}