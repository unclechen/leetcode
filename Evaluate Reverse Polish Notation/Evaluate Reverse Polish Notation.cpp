#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
/*
这道题没有要求我们处理异常，所以是so easy的
1.但是注意：当符号是“-”或者是“/”号时，注意出栈的两个元素，要计算的是op2-op1，而不是op1-op2. 
2.这个题目拓展一下，可以去学习如何将一个中缀表达式转换成一个后缀表达式 
*/
using namespace std;

int evalRPN(vector<string> &tokens) 
{
    int i = 0;
    int len = tokens.size();
    stack<int> number;
    for (i = 0; i < len; ++i)
    {
        int op1, op2, op3;
        if (tokens[i] == "+")
        {
             //if (number.size() < 2) break;
             op1 = number.top();
             number.pop();
             op2 = number.top();
             number.pop();
             op3 = op2 + op1;
             number.push(op3); 
             //cout << op3 << "=" << op1 << "+" << op2 << endl;
        }
        else if (tokens[i] == "-")
        {
             //if (number.size() < 2) break;
             op1 = number.top();
             number.pop();
             op2 = number.top();
             number.pop();
             op3 = op2 - op1;
             number.push(op3); 
             //cout << op3 << "=" << op1 << "-" << op2 << endl;
        }
        else if (tokens[i] == "*")
        {
             //if (number.size() < 2) break;
             op1 = number.top();
             number.pop();
             op2 = number.top();
             number.pop();
             op3 = op2 * op1;
             number.push(op3); 
             //cout << op3 << "=" << op1 << "*" << op2 << endl;
        }
        else if (tokens[i] == "/")
        {
             //if (number.size() < 2) break;
             op1 = number.top();
             number.pop();
             op2 = number.top();
             number.pop();
             op3 = op2 / op1;
             number.push(op3); 
             //cout << op3 << "=" << op1 << "/" << op2 << endl;
        }
        else //if (tokens[i] >= "0" && tokens[i] <= "9")
        {
             //number.push((int)tokens[i]);//atoi()
             number.push( atoi( tokens[i].c_str() ) );
        }
        /*
        else
        {
            break;
        }*/
    }
    if (number.size() == 1 && i == len)
    {
        int result = number.top();
        number.pop();
        return result;
    }
}

int main()
{
    //tokens = ["4", "13", "5", "/", "+"]
    string tokens[] = {"4", "13", "5", "/", "+"};
    size_t tokens_count=sizeof(tokens)/sizeof(string);
    vector<string> vec(tokens, tokens+tokens_count);
    
    int result = evalRPN(vec);
    cout << result << endl;
    
    system("pause");
    return 0;
}
