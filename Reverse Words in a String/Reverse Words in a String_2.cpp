#include <iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std; 

void reverseWords(string &s) 
{
	vector<string> vec;  
    int len=(int)s.length();  
    if(len==0)  
        return;  
    int i=0;  
    int j=len-1;  
    while(i!=len&&s[i]==' ')  
        i++;  
    while(j!=-1&&s[j]==' ')  
        j--;  
    int k=i;  
    while(i<=j){  
        k=i;  
        while(s[i]!=' '&&i<=j)  
            i++;  
        vec.push_back(s.substr(k,i-k));  
        while(s[i]==' '&&i<=j)  
            i++;  
    }  
    if(vec.empty()){  
        s="";  
        return;  
    }  
    
    reverse(vec.begin(),vec.begin()+vec.size());  
    string m=vec[0];  
    for(int i=1;i<vec.size();i++){  
        m+=" ";  
        m+=vec[i];  
    }  
    s=m;  
	
	/*
	int vec_length = vec.size();
	string rs = vec[vec_length-1];
	for (int i = vec_length-2; i >= 0; i--)
	{
		rs += "";
		rs += vec[i];
	}
	s = rs;*/
}  

int main()
{
	//string s = " the  sky is blue  ";
	string s = "hi!";
	//cout << s.length() << endl;
	reverseWords(s);
	cout << s << endl;
	
	return 0;
} 
    
    
