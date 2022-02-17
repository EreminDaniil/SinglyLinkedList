#pragma once
#include <iostream>

typedef std::string Elem;

struct FNode
{
	FNode *Next;
	Elem Value;
};

class USinglyLinkedList
{
public:
	USinglyLinkedList();
	~USinglyLinkedList();
	bool IsEmpty() const;
	size_t Count() const;
	USinglyLinkedList(const USinglyLinkedList &other);
	USinglyLinkedList &operator=(const USinglyLinkedList &other);
	const Elem &Front() const;
	void InsertFront(const Elem &e);
	void EraseFront();
	void Insert(Elem AddValue);
	void Display();
	void quickSort(FNode* Head);
	friend std::ostream& operator<<(std::ostream& out, USinglyLinkedList& l);
	FNode* GetTail(FNode* Current);
	FNode* Partition(FNode* Head, FNode* End, FNode** NewHead, FNode** NewEnd);
	FNode* QuickSortRecur(FNode* Head, FNode* End);
	void QuickSort(FNode** HeadRef);
private:
	FNode* Head;
	FNode* Next;
};