#include<iostream>

using namespace std;
template <typename T>

class Vector
{
private:
	int size;
	int capacity;
	T* bufferPointer;

public:
	Vector()
	{
		capacity = 0;
		size = 0;
		bufferPointer = nullptr;
	}
	~Vector()
	{
		if (bufferPointer != nullptr)
		{
			delete[]bufferPointer;
		}
		
	}
	void PushBack(T data)
	{	
		if (capacity == 0)
		{
			Resize(1);
		}
		else if (capacity <= size)
		{
		
			Resize(capacity*2); 
			bufferPointer[size++] = data;

		}
		else
		{
			bufferPointer[size++] = data;
		}
	
		

	}
	void PopBack()
	{	
		if (size <= 0)
		{
			cout << "Size is empty" << endl;
		}
		else
		{
			bufferPointer[--size] = NULL;
		}
		
		
	
	}
	void Resize(int newSize) 
	{	
		
		if (capacity <= newSize)
		{	
			// capacity =newSize;
			capacity = newSize;
			//2.새로운 포인터 변수를 생성하여 새롭게 만들어진 메모리 공간을 가리키게 함 .
			T* newPointer = new T[capacity];  
			
			
			//3. 새로운 메모리 공간에 값을 초기화 해줌 .
			for (int i = 0; i < capacity; i++)
			{
				newPointer[i] =NULL; 
			}
			//4. 기존 배열에 있을 복사해서 새로운 배열에 넣어줌 
			for (int i = 0; i < size; i++)
			{
				newPointer[i]=bufferPointer[i];
			}
			
			if (bufferPointer != nullptr) 
			{	//5. BufferPointer가 가리키는 메모리 주소 해제
				delete [] bufferPointer;
			}
			//6. Bufferpointer 에 새로운 메모리 주소를 넣어줌.
			bufferPointer = newPointer; 
			
		}
		
		
	}
	void Reserve(int newSize)
	{	
		if (capacity > newSize)
		{
			return;
		}
		else
		{
			capacity = newSize;
			Resize(capacity);

		}
	}
	T& operator [](const int& index)
	{
		return bufferPointer[index];
	}
	int& Size()
	{
		return size;
	}
	
};

		
int main()
{
	Vector <int> vector1;
	vector1.Reserve(5);
	vector1.PushBack(10);
	vector1.PushBack(20);
	vector1.PushBack(30);
	vector1.PushBack(40);
	vector1.PushBack(50);
	vector1.PushBack(60);
	vector1.PushBack(70);
	vector1.PushBack(80);

	



	for (int i = 0; i < vector1.Size(); i++)
	{
		cout << vector1[i]<<" ";
	}
	vector1.PopBack();
	vector1.PopBack();
	vector1.PopBack();
	vector1.PopBack();
	vector1.PopBack();
	vector1.PopBack();
	vector1.PopBack();
	vector1.PopBack();



	

	return 0;
}
	
	
	
	

	




	




	







	
	


	
		
		
		
		
		
