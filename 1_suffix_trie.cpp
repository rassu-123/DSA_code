
#include<iostream>
#include<list>
#define MAX_CHAR 256
using namespace std;
class SuffixTrieNode
{
private:
	SuffixTrieNode *children[MAX_CHAR];
	list<int> indexes;
public:
	SuffixTrieNode() // Constructor
	{//	indexes = new list<int>;
		for (int i = 0; i < MAX_CHAR; i++)
		children[i] = NULL;
	}
	void insertSuffix(string s, int index)
    {
	  indexes.push_back(index);
    	if (s.length() > 0)
	     {char cIndex = s.at(0);
		if (children[cIndex] == NULL)
			children[cIndex] = new SuffixTrieNode();
		children[cIndex]->insertSuffix(s.substr(1), index+1);
	     }
   }
   
	list<int> search(string pat)
	{
	if (pat.length() == 0)
		return indexes;
	if (children[pat.at(0)] != NULL)
		return (children[pat.at(0)])->search(pat.substr(1));
	else 
	{list<int> l;
	    return l;
	}
   }
};
class SuffixTrie
{
private:
	SuffixTrieNode root;
public:
	SuffixTrie(string txt)
	{
		for (int i = 0; i < txt.length(); i++)
			root.insertSuffix(txt.substr(i), i);
	}
	void search(string pat)
	{
	list<int> result = root.search(pat);
	if (result.size() == 0)
		cout << "Pattern not found" << endl;
	else
	{
	list<int>::iterator i;
	int patLen = pat.length();
	for (i = result.begin(); i != result.end(); ++i)
		cout << "Pattern found at position " << *i - patLen<< endl;
	}
}
};

int main()
{
	string txt = "geeksforgeeks.org";
	SuffixTrie S(txt);

	cout << "Search for 'ee'" << endl;
	S.search("ee");

	cout << "\nSearch for 'geek'" << endl;
	S.search("geek");

	cout << "\nSearch for 'quiz'" << endl;
	S.search("quiz");

	cout << "\nSearch for 'forgeeks'" << endl;
	S.search("forgeeks");

	return 0;
}
