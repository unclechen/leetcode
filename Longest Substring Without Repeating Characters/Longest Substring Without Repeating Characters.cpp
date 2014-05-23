#include <iostream>
#include <string>
using namespace std;  
/*这道题我原来在微软电话加试的时候做过了，但是这leetcode中要去的是不只有26个英文字母，还需要包括一些可打印的字符。
因此，这边我将标志数组的大小扩充到了256，因为ascii码表也就只有256个字符，
而能够打印的字符是从空格（space）开始的，空格的ascii值是32,是最小的。 
*/

int lengthOfLongestSubstring(string s) 
{
     int f[256];//利用这个标志数组来检测一个字母是否出现过。面试的时候就是卡在这里了，之前想用遍历来检测 
     int  i, j;
     for(i = 0; i < 256; i++)
     {
           f[i] = 0;
     }
     int  maxi = 0, maxlen = 1;//保存最长不重复字串的开头位置，长度 
     int  len = s.size();
     if (len <= 0)
        return len; 
     i = 0;
     f[ s[i]-' ' ] = 1;
     j = i + 1;
     while (j < len)
     {
           if ( f[ s[j]-' ' ] == 0 )
           {
                f[ s[j]-' ' ] = 1;
                if (j-i+1 > maxlen)
                {
                        maxlen = j-i+1;
                        maxi = i;
                }
                j++; 
           }
           else
           {
               while (s[i] != s[j] )
               {
                     f[ s[i]-' ' ] = 0;
                     i++;
               }
               i++;
               j++;
           }
     }
     /* 
     for (i = maxi; i < maxi+maxlen; i++)
     {
         printf("%c", s[i]);
     }
     printf("\n");
     */
     return maxlen;
}

int main()
{
    //string s = "abcdedabcdef";
    string s = "aaaaa"; 
    cout << lengthOfLongestSubstring(s) << endl;
    
    system("pause");
    return 0;
}
