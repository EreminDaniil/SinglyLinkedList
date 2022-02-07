#include <iostream>
#include <string>
#include "SinglyLinkedList.h"

USinglyLinkedList::USinglyLinkedList()
{
	Head = nullptr;
	Next = nullptr;
}

USinglyLinkedList::~USinglyLinkedList()
{
	FNode* Current = Head;
	while (Current != 0) 
	{
		FNode* Next = Current->Next;
		delete Current;
		Current = Next;
	}
	Head = 0;
}

bool USinglyLinkedList::IsEmpty() const
{
	return (Head == nullptr);
}

size_t USinglyLinkedList::Count() const
{
	FNode* Temp = Head;
	int NumberNode = 0;
	while (Temp != nullptr)
	{
		NumberNode++;
		Temp = Temp->Next;
	}
	return NumberNode;
}

USinglyLinkedList::USinglyLinkedList (const USinglyLinkedList &other)
{
	Head = nullptr;
	FNode* OtherCurrent = other.Head;
	while (OtherCurrent != nullptr)
	{
		Insert(OtherCurrent->Value);
		OtherCurrent = OtherCurrent->Next;
	} 
}

USinglyLinkedList & USinglyLinkedList::operator=(const USinglyLinkedList &other)
{
	if (&other != this) 
	{
		FNode* Temp = Head;
		while (Temp->Next)
		{
			Head = Head->Next;
			delete Temp;
			Temp = Head;
		}
		Temp = other.Head;
		while(Temp)
		{
			Temp = Temp->Next;
		}
	}
	return *this;
}

const Elem & USinglyLinkedList::Front() const
{
	FNode* Current = Head;
	while (Current->Next != nullptr)
	{
		Current = Current->Next;
	}
	return Current->Value;
}

void USinglyLinkedList::InsertFront(const Elem &e)
{
	FNode* Current = Head;
	while (Current->Next != nullptr)
	{
		Current = Current->Next;
	}
	FNode* NewNode = new FNode;
	NewNode->Value = e;
	NewNode->Next = nullptr;
	Current->Next = NewNode;
}

void USinglyLinkedList::EraseFront()
{
	if (Head == nullptr)
	{
		std::cout << "No values!" << std::endl;
		return;
	}
	if (Head->Next == nullptr)
	{
		delete Head;
		return;
	}
	FNode* Current = Head;
	while (Current->Next->Next != nullptr)
	{
		Current = Current->Next;
	}
	delete Current->Next;
	Current->Next = nullptr;
}

void USinglyLinkedList::Insert(Elem AddValue)
{
	FNode* NewNode = new FNode;
	NewNode->Value = AddValue;
	NewNode->Next = nullptr;

	if (Head == nullptr)
	{
		Head = NewNode;
	}
	else
	{
		NewNode->Next = Head;
		Head = NewNode;
	}
}

void USinglyLinkedList::Display()
{
	FNode* Temp = Head;
	while (Temp != nullptr)
	{
		std::cout << Temp->Value << " ";
		Temp = Temp->Next;
	}
	std::cout << std::endl;
}

std::ostream& operator<<(std::ostream& out, USinglyLinkedList& l)
{
	FNode* Current = l.Head;
	while (Current != nullptr)
	{
		out << Current->Value << std::endl;
		Current = Current->Next;
	}
	return out;
}

int main() {

	USinglyLinkedList List;

	List.Insert("Monday");
  	List.Insert("Thuesday");
	List.Insert("Saturday");
	List.Insert("Friday");
	List.Insert("Sunday");
	std::cout << List << std::endl;
}