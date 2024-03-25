#include<iostream>

using namespace std;

template <typename T>
#define SIZE 10
class Stack
{
private:
	int top;
	 T buffer[SIZE];

public:
	Stack()
	{
		for (int i = 0; i < SIZE; i++)
		{
			buffer[i] = NULL;
		}
		top = -1;
	}
	~Stack()
	{
		if (buffer[top] == NULL)
		{
			Pop();
		}
	}
	void Push(T data)
	{
		if (IsFull())
		{
			cout << "Stack is Full"<<endl;
		}
		else
		{
			
			buffer[++top] = data;
		}
	}
	T Pop()
	{
		if (Empty())
		{
			cout << "Stack is Empty"<<endl;
		}
		else
		{
			return buffer[top--];
			
		}

	}

	bool Empty()
	{
		if (top <= -1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	bool IsFull()
	{
		if (top >= SIZE-1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	T& Top()
	{
		return buffer[top]; 
	}

};

bool CheckBracket(string content)
{
	// ) } ] ( a [i+1] =0;}
	Stack <char> stack;

	for (int i = 0; i < content.length(); i++)
	{
		if (content[i] == '(' || content[i] == '{' || content[i] == '[')
		{
			stack.Push(content[i]);
		}
		if (content[i] == ')' || content[i] == '}' || content[i] == ']')
		{
			
			if(stack.Top()=='('&&content[i]==')')
			{
				stack.Pop();

			}
			else if (stack.Top() == '{' && content[i] == '}')
			{
				stack.Pop();

			}
			else if (stack.Top() == '[' && content[i] == ']')
			{
				stack.Pop();

			}
			else
			{
				return false;
			}


			
			
		}
		
	}

if (stack.Empty())
{
	return true;
}
else
{
	return false;
}
	
	
}

		
int main()
{
	
	
	//Stack <int> stack;

	//for (int i = 1; i <= SIZE; i++)
	//{
	//	stack.Push(i * 10);
	//}

	//while (stack.Empty() != true)
	//{
	//	cout << "|" << stack.Top() << "|" << endl;
	//	stack.Pop();
	//}
	string flag = "[{()}]";
	cout << CheckBracket(flag);
	return 0;
}
	
	
	
	

	




	




	







	
	


	
		
		
		
		
		
