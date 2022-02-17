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
	std::cout << "word";
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

FNode* USinglyLinkedList::GetTail(FNode* Current)
{
	while (Current != nullptr && Current->Next != nullptr)
	{
		Current = Current->Next;
	}
	return Current;

}

FNode* USinglyLinkedList::Partition(FNode* Head, FNode* End, FNode** NewHead, FNode** NewEnd)
{
	FNode* Pivot = End;
	FNode* Prev = nullptr, * Current = Head, * Tail = Pivot;
	while (Current != Pivot)
	{
		if (Current < Pivot)
		{
			if (*NewHead == nullptr)
			{
				*NewHead = Current;
			}
			Prev = Current;
			Current = Current->Next;
		}
		else
		{
			if (Prev)
			{
				Prev->Next = Current->Next;
			}
			FNode* Temp = Current->Next;
			Current->Next = nullptr;
			Tail->Next = Current;
			Tail = Current;
			Current = Temp;
		}
	}
	if (*NewHead == nullptr)
	{
		*NewHead = Pivot;
	}
	*NewEnd = Tail;
	return Pivot;
}

FNode* USinglyLinkedList::QuickSortRecur(FNode* Head, FNode* End)
{
	if (!Head || (Head == End))
	{
		return Head;
	}
	FNode* NewHead = nullptr, *NewEnd = nullptr;
	FNode* Pivot = Partition(Head, End, &NewHead, &NewEnd);
	if (NewHead != Pivot)
	{
		struct FNode* Temp = NewHead;
		while (Temp->Next != Pivot)
		{
			Temp = Temp->Next;
		}
		Temp->Next = nullptr;
		NewHead = QuickSortRecur(NewHead, Temp);
		Temp = GetTail(NewHead);
		Temp->Next = Pivot;
	}
	Pivot->Next = QuickSortRecur(Pivot->Next, NewEnd);
	return NewHead;
}

void USinglyLinkedList::QuickSort(FNode** HeadRef)
{
	*HeadRef = QuickSortRecur(*HeadRef, GetTail(*HeadRef));
	return;
}


FNode* USinglyLinkedList::Middle(FNode* Start, FNode* Last)
{
	if (Start == nullptr)
	{
		return nullptr;
	}
	FNode* Slow = Start;
	FNode* Fast = Start->Next;

	while (Fast != Last)
	{
		Fast = Fast->Next;
		if (Fast != Last)
		{
			Slow = Slow->Next;
			Fast = Fast->Next;
		}
	}
	return Slow;
}

FNode* USinglyLinkedList::BinarySearch(FNode* Head, Elem Value)
{
	FNode* Start = Head;
	FNode* Last = nullptr;
	do
	{
		FNode* Mid = Middle(Start, Last);
		if (Mid == nullptr)
		{
			return nullptr;
		}
		if (Mid->Data == Value)
		{
			return Mid;
		}
		else if (Mid->Data < Value)
		{
			Start = Mid->Next;
		}
		else
		{
			Last = Mid;
		}

	} 
	while (Last == nullptr || Last != Start);

	return nullptr;
	
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
	List.Insert("Sunday");

	std::cout << List << std::endl;
	List.~USinglyLinkedList();
	std::cout << List << std::endl;
}