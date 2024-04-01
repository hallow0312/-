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
	~Trie()
	{
		for (int i = 0; i < COUNT; i++)
		{
			if (alphabet[i] != nullptr)
			{
				delete alphabet[i];
			}
		}

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

	bool Find(const char* content)
	{
		if (*content == '\0')
		{
			if (final == true)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			int index = *content - 'A';
			if (alphabet[index] == nullptr)
			{
				return false;
			}

			alphabet[index]->Find(content + 1);
		}
	}



};


int main()
{
#pragma region 트라이

	//문자열의 길이 M
	// A~Z;
	// 문자열 "Kone","Korea" "Sound","Kill" 
	Trie trie;
	trie.Insert("KOREA");

	cout << trie.Find("KOREA") << endl;


#pragma endregion









	return 0;
}