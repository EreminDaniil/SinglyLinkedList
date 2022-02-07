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
	friend std::ostream& operator<<(std::ostream& out, USinglyLinkedList& l);
private:
	FNode* Head;
	FNode* Next;
};