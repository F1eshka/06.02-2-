#include <iostream>
#include <ctime>
using namespace std;

class ArrayList 
{
	unsigned int size = 0; 
	unsigned int capacity = 10; 
	int* data = nullptr; 

public:

	ArrayList(const ArrayList& original)
	{
		this->size = original.size;
		this->capacity = original.capacity;
		this->data = new int[original.size];

		for (int i = 0; i < size; i++)
		{
			this->data[i] = original.data[i];
		}
	}

	ArrayList() : ArrayList(10)
	{
		 cout << "without params\n";
	}

	ArrayList(unsigned int capacity)
	{
		if (capacity < 10)
		{
			capacity = 10;
		}
		this->capacity = capacity;
		data = new int[capacity];
		 cout << "With params\n";
	}

	~ArrayList()
	{
		 cout << "Destructor\n";
		if (data != nullptr)
		{
			delete[] data;
			data = nullptr;
		}
	}

	void PushBack(int value)
	{
		EnsureCapacity(); 
		data[size] = value;
		size++;
	}

	void PushFront(int value)
	{
		EnsureCapacity();
		for (int i = size; i > 0; i--) 
		{
			data[i] = data[i - 1]; 
		}
		data[0] = value;
		size++;
	}

	void EnsureCapacity()
	{
		if (size < capacity)return;

		int* temp = new int[size * 2];
		for (int i = 0; i < size; i++)
		{
			temp[i] = data[i];
		}
		delete[]data;
		data = temp;

		capacity *= 2;
	}


	void Clear()
	{
		size = 0;
	}

	bool IsEmpty() const
	{
		return size == 0;
	}

	void Print() const
	{
		if (IsEmpty())
		{
			cout << "Vector is empty.\n";
			return;
		}

		for (int i = 0; i < size; i++)
		{
			cout << data[i] << " ";
		}
		cout << "\n";
	}

	void SetCapacity(unsigned int capacity)
	{
		this->capacity = capacity;
	}
	unsigned int GetCapacity()
	{
		return capacity;
	}

	unsigned int GetSize()
	{
		return size;
	}

	void RemoveAt(unsigned short index)
	{
		if (index >= size)
		{
			cout << "Index out of bounds\n";
			return;
		}
		int* temp = new int[size - 1];
		for (int i = 0, j = 0; i < size; i++)
		{
			if (i != index)
			{
				temp[j++] = data[i];
			}
		}
		delete[] data;
		size--;
		data = temp;
	}

	void PopFront()
	{
		if (size == 0)
		{
			cout << "Vector is empty.\n";
			return;
		}

		for (int i = 0; i < size - 1; i++)
		{
			data[i] = data[i + 1];
		}
		size--;
	}

	void PopBack()
	{
		if (size == 0)
		{
			cout << "Vector is empty.\n";
			return;
		}
		size--;
	}

	void RandomFill(int size)
	{
		EnsureCapacity();
		for (int i = 0; i < size; i++)
		{
			data[i] = rand() % 12;
		}
		this->size = size;
	}

	void Insert(int index, int value)
	{
		if (index < 0 || index > size)
		{
			cout << "Invalid index\n";
			return;
		}
		EnsureCapacity();

		for (int i = size; i > index; i--)
		{
			data[i] = data[i - 1];
		}
		data[index] = value;
		size++;
	}


};

unsigned int operator == (ArrayList& a, ArrayList& b)
{
	return a.GetSize() == b.GetSize();
}

ostream& operator << (const ostream& i, ArrayList& d)
{
	d.Print();
	return cout;
}

istream& operator >> (istream& is, ArrayList& arr)
{
	cout << "Enter array: ";
	int answear;
	cin >> answear;
	arr.PushFront(answear);
	return cin;
}
int main()
{
	srand(time(NULL));

	ArrayList arr;
	arr.Print();

	arr.PushBack(1);
	arr.PushBack(2);
	arr.PushBack(3);
	arr.PushBack(4);
	arr.PushBack(5);
	arr.PushBack(6);
	arr.PushBack(7);
	arr.PushBack(8);
	arr.PushBack(9);
	arr.PushBack(10);
	arr.PushBack(11);
	arr.Print();
	arr.RemoveAt(5);
	arr.Print();

	arr.PushFront(1);
	arr.PushFront(2);
	arr.PushFront(3);
	arr.PushFront(4);
	arr.PushFront(5);
	arr.PushFront(6);
	arr.PushFront(7);
	arr.PushFront(8);
	arr.PushFront(9);
	arr.PushFront(10);
	arr.PushFront(11);
	arr.RandomFill(11);
	arr.Insert(2, 12);
	

	ArrayList copy;
	copy = arr;
	copy.Print();
	ArrayList arra;
	arra.PushFront(1);
	arra.PushFront(2);
	arra.PushFront(3);
	arra.PushFront(4);
	arra.PushFront(5);
	arra.PushFront(6);
	arra.PushFront(7);
	arra.PushFront(8);
	arra.PushFront(9);
	arra.PushFront(10);
	arra.PushFront(11);

	if (arra == arr)
	{
		cout << "==";
	}

	arr.PushBack(1);
	arr.PushBack(12);

	
	arr.Print();
	cin >> arr;
	cout << arr;

}