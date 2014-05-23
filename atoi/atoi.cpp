#include <iostream>
#include <string.h>
#include <vector>
#include <LIMITS.H>
using namespace std;

int atoi(const char *str) 
{
    int len = strlen(str);
    if (len < 1)
        return 0;
    int int_max = 0X7FFFFFFF;
    int int_min = -int_max-1;
    int sign = 1;
    vector<int> numbers;
    int i;
    i = 0; 
    while (str[i] == ' ' && i < len)
    {
        i++;
    }
    //cout << i << endl;
    if (i == len)
    {
        return 0;
    }
    if (str[i] == '+' )
    {
        sign = 1;
        i++;
    }
    else if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    //cout << i << endl;
    //处理完了空格和符号位 
    //假如接下来的字符第一个不是 数字的话，就要排除 
    if (i == len || str[i] < '0' || str[i] > '9')
    {
        return 0;
    }
    /* 
    while (i < len )
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            numbers.push_back(str[i++] - '0');
        }
        else
        {
            i++;
        } 
    }
    */
    while (i < len && str[i] >= '0' && str[i] <= '9')
    {
        numbers.push_back(str[i++] - '0');
    }
    long long ret = 0;
    //cout << numbers.size() << endl; 
    for (int j = 0; j < numbers.size(); j++)
    {
    	//cout << numbers[j] << endl; 
        ret = 10 * ret + numbers[j];
        //cout << ret << endl;
        if (ret > int_max && sign == -1)
        {
        	//cout << ret << endl; 
            return int_min;
        }
        else if (ret >= int_max && sign == 1) 
        {
            return int_max; 
        }
        assert(ret <= int_max); 
    }
    
    return (int)sign*ret;
} 

int main()
{
    char *p = "-1";
    //char *p = "1";
    cout << atoi(p) << endl;
    
    return 0;
}

