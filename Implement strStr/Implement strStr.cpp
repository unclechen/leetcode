#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
/*暴力法搜索，O(n*n)复杂度，提交超时了。。 
*/ 
/*
char *strStr(char *haystack, char *needle) 
{
	if (haystack == NULL || needle == NULL)
		return NULL;
	char *ptr = haystack;
	char *start = NULL; 
	while (*ptr != '\0')
	{
		start = ptr;
		char *p2 = needle;
		char *p1 = ptr;
		while (*p1 == *p2 && *p1 != '\0')
		{
			p1++;
			p2++;
		}
		if (*p2 == '\0')
		{
			break;
		}
		else
		{
			ptr ++;
		}
		
		
	}
	return start;
}
*/
/*
1、process函数来自于kmp的处理，计算出覆盖数组overlay 
2、然后利用覆盖数组进行跳跃式的匹配 
*/ 
void process(char *needle, int *overlay) 
{
	int i = 0;
	overlay[0] = -1;
	int index = 0; 
	int len = strlen(needle);
	for (i = 1; i < len; i++)
	{
		index = overlay[i-1];
		while ( index >= 0 && *(needle+i) != *(needle+index+1) ) 
		{
			index = overlay[index];
		}
		if ( *(needle+index+1) == *(needle+i) )
		{
			overlay[i] = index + 1; 
		}
		else
		{
			overlay[i] = -1;
		}
	}
}

char *strStr(char *haystack, char *needle) 
{
	int needle_len = strlen(needle);
	int *overlay = (int*) malloc ( needle_len * sizeof(int) );
	process(needle, overlay);	
	int haystack_len = strlen(haystack);
	int haystack_index = 0; //怎么说呢，在这里之前使用的是int haystack_index, needle_index = 0; 结果haystack_index居然没有被赋值为 0 
	int needle_index = 0;
	char *position = NULL;
	while (haystack_index < haystack_len && needle_index < needle_len)
	{
		if(*(haystack + haystack_index) == *(needle + needle_index) )
		{
			haystack_index++;
			needle_index++;
		}
		else if (needle_index == 0)
		{
			haystack_index ++;
		}
		else
		{
			needle_index = overlay[needle_index-1] + 1;
		}
	}
	//int pos = -1;
	if (needle_index == needle_len)
	{
		position = haystack + haystack_index - needle_len;
		//pos = haystack_index - needle_len;
	}
	
	free(overlay);
	overlay = NULL;

	return position;
}

int main()
{
	char *haystack = "aababa";
	char *needle = "abab";
	char *result = strStr(haystack, needle);
	printf("%c\n", *result);
	
	return 0;
}
