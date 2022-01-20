#include <iostream>
#include <string>
#include "SinglyLinkedList.h"


typedef std::string Elem;

struct Node 
{ 
	Node *Next; 
	Elem Value; 
};

class SinglyLinkedList
{
public:
	SinglyLinkedList::SinglyLinkedList()
	{
		Head = nullptr;
	}

	SinglyLinkedList::~SinglyLinkedList()
	{
		Node* Current = Head;
		Node* Next;

		while (!IsEmpty())
		{
			Next = Current->Next;
			delete Current;
			Current = Next;
		}
	}

	bool SinglyLinkedList::IsEmpty() const
	{
		return (Head == nullptr);
	}

	size_t SinglyLinkedList::Count() const
	{
		Node* Temp = Head;
		int NumberNode = 0;
		while (Temp != nullptr)
		{
			NumberNode++;
			Temp = Temp->Next;
		}
		return NumberNode;
	}

	SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList &other)
	{
		Head = nullptr;
		Node* OtherCurrent = other.Head;
		while (OtherCurrent != nullptr)
		{
			Insert(OtherCurrent->Value);
			OtherCurrent = OtherCurrent->Next;
		} 
	}

	SinglyLinkedList::SinglyLinkedList &operator=(const SinglyLinkedList &other)
	{
		if (&other != this) 
		{
			Node* Temp = Head;
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

	const SinglyLinkedList::Elem &Front() const
	{
		Node* Current = Head;
		while (Current->Next != nullptr)
		{
			Current = Current->Next;
		}
		return Current->Value;
	}

	void SinglyLinkedList::InsertFront(const Elem &e)
	{
		Node* Current = Head;
		while (Current->Next != nullptr)
		{
			Current = Current->Next;
		}
		Node* NewNode = new Node;
		NewNode->Value = e;
		NewNode->Next = nullptr;
		Current->Next = NewNode;
	}

	void SinglyLinkedList::EraseFront()
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
		Node* Current = Head;
		while (Current->Next->Next != nullptr)
		{
			Current = Current->Next;
		}
		delete Current->Next;
		Current->Next = nullptr;
	}

	void SinglyLinkedList::Insert(Elem AddValue)
	{
		Node* NewNode = new Node;
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

	void SinglyLinkedList::Display()
	{
		Node* Temp = Head;
		while (Temp != nullptr)
		{
 			std::cout << Temp->Value << " ";
 			Temp = Temp->Next;
		}
		std::cout << std::endl;
	}

 	friend std::ostream& operator<<(std::ostream& out, SinglyLinkedList &l)
 	{
		Node* Current = l.Head;
		Node* Next;

		while (!l.IsEmpty())
		{
			Next = Head;
			Next = Current->Next;
			Current = Next;
			if (Current != nullptr)
			{
				out << (*Current).Value << std::endl;
			}
			
		}
		return out;
	}

private:
	Node* Head;
};

int main() {

	SinglyLinkedList List;

	List.EraseFront();


	List.Insert("Monday");
  	List.Insert("Thuesday");
	std::cout << List << std::endl;
//  	List.Insert(1);
//  	List.Insert(3);
//  	List.Insert(7);
// 	List
// 	List.Delete(9);
// 	std::cout << "Current Linked List: ";
// 	List.Display();

// 	std::cout << "Deleting 1: ";
// 	List.Delete(1);
// 	List.Display();
// 
// 	std::cout << "Deleting 13: ";
// 	
// 	List.Insert(3);
// 
// 	std::cout << "Searching for 7: ";
// 	std::cout << List.Search(7) << std::endl;
// 
// 	std::cout << "Searching for 13: ";
// 	std::cout << List.Search(13) << std::endl;
}