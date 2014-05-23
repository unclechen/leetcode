#include "iostream"
#include "string"
using namespace std;

class Solution {
public:
	//这个函数作为核心功能，负责将一个字符串完全反转。
	//空格处理交给reverseWords函数来实现 
    void reverseCore(string &s, int l, int r)
	{
		int i = l;
		int j = r;
		while(i < j)
		{
			char temp = s[i];
			s[i] = s[j];
			s[j] = temp;
			i++;
			j--;
		}
	}
void reverseWords(string &s)
{
	//cout << s << endl;
	reverseCore (s, 0, s.length()-1);
	//cout << s << endl;
	 
	int i, j = 0; //两个指针，分别记录一个单词两边的空格位置
	while (i < s.length())
	{
		if (s[i] == ' ')
		{
			i++;
			j++;
		}
		else if (j == s.length() || s[j] == ' ')
		{
			int l = i;
			int r = j-1;
			reverseCore(s, l, r);
			i = j++;
		}
		else
		{
			j++;
		}
	}
	//这里将中间多余的空格处理掉
	string rs;
	for (i = 0; i < s.length(); ++i)
	{
		int space;
		if (s[i] == ' ')
		{
			space = 1;
			continue;
		}
		if (space == 1)
		{
			rs += " " ;
			rs += s[i];
			space = 0;
		}
		else
		{
			rs += s[i];
		}
	}
	s = rs;
	//cout << s << endl;
	//
	i = 0;
	j = s.length()-1;
	//cout << i << "," << j <<endl;
	while ( i <= s.length()-1 )
	{
		if (i == s.length()-1)
		{
			break;
		}
		if (s[i] == ' ')
		{
			i++;
		}
		else
		{
			break;
		}
	}
	//cout << i << endl;
	while ( j >= 0 )
	{
		if (j == 0)
			break;
		if (s[j] == ' ')
		{
			j--;
		}
		else
		{
			break;
		}
	}
	//cout << j << endl;
	
	rs = "";
	while (i <= j)
	{
		rs += s[i++];	
	}
	s = rs;
	//cout << s << endl;
}
};
/*题目还要求：
1.输入可以以空格开头或者结尾
2.输出时，开头、结尾不能为空格；多个空格缩减为一个空格
3.标点符号，不改变位置 ???在本地而是已经是正确的了，但是为啥放上去说：“hi！”输出的是“！ih” ，自己机器上跑的结果就是“hi！”啊 
*/
int main()
{
	//string s = " the  sky is blue  ";
	string s = "hi!";
	//cout << s.length() << endl;
	Solution* mySolution =  new Solution(); 
	mySolution->reverseWords(s);
	cout << s << endl;
	
	return 0;
} 
