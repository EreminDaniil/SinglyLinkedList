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
	SinglyLinkedList() 
	{
		Head = nullptr;
	}

	~SinglyLinkedList()
	{
		Node* Current = Head;
		Node* Next;

		while (!IsEmpty()-1)
		{
			Next = Current->Next;
			delete Current;
			Current = Next;
		}
	}

	bool IsEmpty() const
	{
		return (Head == nullptr);
	}

	size_t Count() const
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

	SinglyLinkedList (const SinglyLinkedList &other)
	{
		Head = nullptr;
		Node* OtherCurrent = other.Head;
		while (OtherCurrent != nullptr)
		{
			Insert(OtherCurrent->Value);
			OtherCurrent = OtherCurrent->Next;
		} 
	}

	SinglyLinkedList &operator=(const SinglyLinkedList &other)
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

	const Elem &Front() const
	{
		Node* Current = Head;
		while (Current->Next != nullptr)
		{
			Current = Current->Next;
		}
		return Current->Value;
	}

	void InsertFront(const Elem &e)
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

	void EraseFront()
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

	void Insert(Elem AddValue)
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

	void Display()
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
		while (Current != nullptr)
		{
			out << Current->Value << std::endl;
			Current = Current->Next;
		}
		return out;
	}

private:
	Node* Head;
	Node* Next;
};

int main() {

	SinglyLinkedList List;

	List.Insert("Monday");
  	List.Insert("Thuesday");
	List.Insert("Saturday");
	List.Insert("Friday");
	List.Insert("Sunday");
	std::cout << List << std::endl;
}