#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

bool wordBreak(string s, unordered_set<string> &dict) 
{
    bool ret;

    return true;
}

/*
For example, given
s = "leetcode",
dict = ["leet", "code"].
Return true because "leetcode" can be segmented as "leet code".
*/

int main()
{
    string s = "leetcode";
    unordered_set<string> &dict = {"leet", "code"};

    bool ret = wordBreak(s, dict);
    if (ret)
        cout << "true" << endl;
    else 
        cout << "false" << endl;

    system("pause");
    return 0;
}
