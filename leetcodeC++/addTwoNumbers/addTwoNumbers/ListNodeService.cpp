#include "stdafx.h"
#include "ListNodeService.h"


ListNodeService::ListNodeService()
{
	// ��������
	CreateList();
}


ListNodeService::~ListNodeService()
{
	// �������
	ClearList();
}


//����ͷ���
void ListNodeService::CreateList()
{
	head = new ListNode(0);
}
//��ͷ����һ���ڵ�
void ListNodeService::Insert2List(const int& d)
{
	ListNode *p = new ListNode(d);
	p->next = head->next;
	head->next = p;
}
//��ӡ����
void ListNodeService::PrintList()
{
	for (ListNode * p = head->next; p; p = p->next){
		cout << p->val << endl;
	}
}
//��dλ��֮ǰ����d1
void ListNodeService::InsertByPos(const int& d, const int& d1)
{
	ListNode * p = FindListByData(d);
	ListNode * q = new ListNode(d1);
	q->next = p->next;
	p->next = q;
}

//ɾ��
void ListNodeService::EraseByData(const int& d)
{
	ListNode * p = FindListByData(d);
	//��Ϊp����һ���ڵ��λ�ã���q������
	//Ҫɾ���Ľڵ�ĵ�ַ
	ListNode *q = p->next;
	//ͨ������һ���ڵ��nextָ��ָ��Ҫɾ���ڵ��nextָ
	//��־��Ľڵ�ʵ�ֶϿ�Ҫɾ���ڵ��Ŀ��
	p->next = p->next->next;
	//ɾ��Ҫɾ���Ľڵ�q
	delete q;
}

//�޸�ָ������
void ListNodeService::UpdataByData(const int& d, const int& d1)
{
	ListNode * p = FindListByData(d);
	p->next->val = d1;
}

//��ת����
void ListNodeService::ReverseList()
{
	ListNode * p = head->next;//ͷ���֮��ĵ�1���ڵ�
	ListNode * q = head->next->next;//ͷ���֮��ĵ�2�ڵ�
	ListNode * m = head->next->next->next;//ͷ���֮��ĵ�3���ڵ�
	p->next = NULL;//��ͷ�ӵ�֮��ĵ�1���ڵ��nextָ����Ϊ��
	//����m�Ƿ�Ϊ�����ж� �Դ�����ÿһ���ڵ�
	while (m){
		q->next = p;
		p = q;
		q = m;
		m = m->next;
	}
	//�����һ���ڵ�����
	q->next = p;
	//��ͷ����ָ���µĵĵ�1���ڵ�(֮ǰ�����һ���ڵ�)
	head->next = q;
}

//����������
void  ListNodeService::ClearList(){
	ListNode * p = head;
	//��ͷ�ڵ㿪ʼѭ��ɾ��
	while (p){
		ListNode * q = p->next;
		delete p;
		p = q;
	}
}
//��������d����һ���ڵ�λ�õĺ���
//Ϊ�˷������ɾ������
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