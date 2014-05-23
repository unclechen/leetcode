#include <iostream>
#include <string>
using namespace std;

/*
*/ 

bool isPalindrome(string s, int left, int right)
{
	int i = left;
	int j = right;
	while (i < j)
	{
		if(s[i] == s[j])
		{
			i++;
			j--;
		}
		else
		{
			break;
		}
	}
	if (i >= j)
	{
		return true;
	}
	else
	{
		return false;
	}
}

string longestPalindrome(string s) 
{
	int i, j;
	int len = s.length();
	if (len <= 1)
	{
		return s;
	}
	int maxpos = -1;
	int maxlen = 0;
	for(i = 0; i < len; i++)
	{
		for (j = i + 1; j < len ; j++)
		{
			if ( isPalindrome(s, i, j) )
			{
				if (j-i+1 > maxlen)
				{
					maxlen = j-i+1;
					maxpos = i;
				}
			}
		}
	}
	
	string ret = s.substr(maxpos, maxlen);
	//cout << ret << endl;
	
	return ret;
}

int main()
{
	string s = "a";
	cout << longestPalindrome(s);
	
	return 0; 
}
