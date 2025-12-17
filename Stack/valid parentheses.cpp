/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <bits/stdc++.h>
using namespace std;

bool validParanthesis(string s)
{
    std::vector<char>v ;
    for(char c:s)
    {
        if(c=='(' || c=='{'|| c=='[')
        {
            v.push_back(c);
        }
        else
        {
            if(v.empty()) return false;
            
            char top=v.back();
            v.pop_back();
            
            // if(top!='(' || top!='{' || top!='[') return false;
            if(c==')' && top=='(') continue;
            else if(c=='}' && top=='{') continue;
            else if(c==']' && top=='[') continue;
            else return false;
            
            
            
        }
    }
    
    return v.empty();
}

int main()
{
   

   string s="(([]{}))()()(){";
   cout<<validParanthesis(s);
   
    return 0;
}
