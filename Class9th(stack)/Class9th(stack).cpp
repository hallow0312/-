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
			cout << "Stack is Full" << endl;
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
			cout << "Stack is Empty" << endl;
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
		if (top >= SIZE - 1)
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

bool CheckBracket(string content) //괄호 검사 
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

			if (stack.Top() == '(' && content[i] == ')') //서로 짝이 맞으면 pop
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
			else // 짝이 안맞을 시 false 출력 
			{
				return false;
			}




		}

	}

	if (stack.Empty()) //stack문 이 전부 pop 이되었다면 
	{
		return true;
	}
	else
	{
		return false; //안됏으면 false 
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
	string flag = "[{(stack flag)}]";
	if (CheckBracket(flag) == true)
	{
		cout << flag << " : " << "true";
	}
	else
	{
		cout << flag << " : " << "false";
	}
	return 0;
}

































