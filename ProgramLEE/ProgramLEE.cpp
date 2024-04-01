#include<iostream>
using namespace std;
	
#define COUNT 26
class Trie
{

private:
	Trie* alphabet[COUNT]; 
	bool final;

public:
	Trie()
	{
		for (int i = 0; i < COUNT; i++)
		{
			alphabet[i] = nullptr; 
		}
		final = false;
	}
	void Insert(const char* content)
	{	
		if (*content == '\0')
		{
			final = true;
			return;
		}
		else
		{
			int index = *content - 'A';
			if (alphabet[index] == nullptr)
			{
				alphabet[index] = new Trie();
			}
			
			alphabet[index]->Insert(content + 1);
			
		}
		
	}
	Trie *Find(const char* content)
	{
		if (*content == '\0')
		{
		
			return this;

		}
		else
		{
			int index = *content - 'A';
			if (alphabet[index] == nullptr)
			{
				return NULL;
			}
			else
			{
				alphabet[index]->Find(content + 1);
			}
		}
		
	}
};
			
			
int main()
{
#pragma region 트라이

	//문자열의 길이 M
	// A~Z;
	// 문자열 "Kone","Korea" "Sound","Kill" 
	
#pragma endregion

			
			
			





	return 0; 
}