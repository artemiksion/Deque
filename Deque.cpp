#include <iostream>
#include <conio.h>
using namespace std;

class Deque
{
private:
	struct NodeOfDeque
	{
	public:
		NodeOfDeque* Left;
		NodeOfDeque* Right;
		int info;

		NodeOfDeque()
		{
			info = 0;
			Left = Right = nullptr;
		}
	};
	NodeOfDeque* Back;
	NodeOfDeque* Front;

	void MemoryAllocationFromBack()
	{
		if (Back != nullptr)
		{
			Back->Left = new NodeOfDeque;
			Back->Left->Right = Back;
			Back = Back->Left;
		}
		else
		{
			Back = Front = new NodeOfDeque;
		}
	}

	void MemoryAllocationFromFront()
	{
		if (Front != nullptr)
		{
			Front->Right = new NodeOfDeque;
			Front->Right->Left = Front;
			Front = Front->Right;
		}
		else
			Back = Front = new NodeOfDeque;
	}
public:
	Deque()
	{
		Back = Front = nullptr;
	}

	~Deque()
	{
		Clear();
	}

	void PushBack()
	{
		try
		{
			MemoryAllocationFromBack();
			cout << "Input element" << endl;
			int value;
			while (true)
			{
				cin >> value;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Repeat input" << endl;
				}
				else
				{
					Back->info = value;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					return;
				}
			}
		}
		catch (bad_alloc)
		{
			cout << "Error of memory allocation" << endl;
			_getch();
			return;
		}
	}

	void PushFront()
	{
		try
		{
			MemoryAllocationFromFront();
			cout << "Input element" << endl;
			int value;
			while (true)
			{
				cin >> value;
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Repeat input" << endl;
				}
				else
				{
					Front->info = value;
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					return;
				}
			}
		}
		catch (bad_alloc)
		{
			cout << "Error of memory allocation" << endl;
			_getch();
			return;
		}
	}

	void PopBack()
	{
		if ((Back != nullptr) && (Back != Front))
		{
			Back = Back->Right;
			delete Back->Left;
			Back->Left = nullptr;
		}
		else
		{
			if (Back != nullptr)
			{
				delete Back;
				Back = Front = nullptr;
			}
			else
			{
				cout << "Deque is clear" << endl;
				_getch();
			}
		}
	}

	void PopFront()
	{
		if ((Front != nullptr) && (Back != Front))
		{
			Front = Front->Left;
			delete Front->Right;
			Front->Right = nullptr;
		}
		else
		{
			if (Front != nullptr)
			{
				delete Front;
				Front = Back = nullptr;
			}
			else
			{
				cout << "Deque is clear" << endl;
				_getch();
			}
		}
	}

	void IsEmpty()
	{
		if (Back == nullptr)
			cout << "Deque is empty" << endl;
		else
			cout << "Deque isn't empty" << endl;
		_getch();
	}

	void Clear()
	{
		while (Back != nullptr)
		{
			if (Back->Right != nullptr)
			{
				Back = Back->Right;
				delete Back->Left;
			}
			else
			{
				delete Back;
				Back = Front = nullptr;
			}
		}
	}

	void ShowDequeFromBackToFront()
	{
		NodeOfDeque* P = Back;
		if (P == nullptr)
		{
			cout << "No elements in the deque" << endl;
			_getch();
			return;
		}
		while (P != nullptr)
		{
			cout << P->info << " ";
			P = P->Right;
		}
		_getch();
	}

	void ShowDequeFromFrontToBack()
	{
		NodeOfDeque* P = Front;
		if (P == nullptr)
		{
			cout << "No elements in the deque" << endl;
			_getch();
			return;
		}
		while (P != nullptr)
		{
			cout << P->info << " ";
			P = P->Left;
		}
		_getch();
	}
};

void CorrectInputOfChoice(int& choice)
{
	while (true)
	{
		choice = _getch() - 48;
		if ((choice >= 1) && (choice <= 9))
			return;
	}
}

int main()
{
	Deque DequeWithIntValues;

	while (true)
	{
		cout << "Choose action with deque:" << endl;
		cout << "1.Push element to back" << endl;
		cout << "2.Push element to front" << endl;
		cout << "3.Pop element from back" << endl;
		cout << "4.Pop element from front" << endl;
		cout << "5.Show elements from back to front" << endl;
		cout << "6.Show elements from front to back" << endl;
		cout << "7.Is deque empty or not" << endl;
		cout << "8.Clear the deque" << endl;
		cout << "9.Exit" << endl;
		int choice;
		CorrectInputOfChoice(choice);
		switch (choice)
		{
		case 1:
			DequeWithIntValues.PushBack();
			break;
		case 2:
			DequeWithIntValues.PushFront();
			break;
		case 3:
			DequeWithIntValues.PopBack();
			break;
		case 4:
			DequeWithIntValues.PopFront();
			break;
		case 5:
			DequeWithIntValues.ShowDequeFromBackToFront();
			break;
		case 6:
			DequeWithIntValues.ShowDequeFromFrontToBack();
			break;
		case 7:
			DequeWithIntValues.IsEmpty();
			break;
		case 8:
			DequeWithIntValues.Clear();
			break;
		case 9:
			return 0;
		}
		system("cls");
	}
}