// #pragma once
// #include <iostream>
// 
// typedef std::string Elem;
// 
// // struct Node
// // {
// // 	Node *Next;
// // 	Elem Value;
// // };
// 
// class SinglyLinkedList
// {
// public:
// 	SinglyLinkedList();
// 	~SinglyLinkedList();
// 	bool IsEmpty() const;
// 	size_t Count() const;
// 	SinglyLinkedList(const SinglyLinkedList &other);
// 	SinglyLinkedList &operator=(const SinglyLinkedList &other);
// 	const Elem &Front() const;
// 	void InsertFront(const Elem &e);
// 	void EraseFront();
// 	void Insert(Elem AddValue);
// 	void Display();
// private:
// 	Node* Head;
// };