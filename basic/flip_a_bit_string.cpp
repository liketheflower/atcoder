#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s = "0011";
    for (auto& c : s) c = '0' + '1' - c;
    cout<<s<<endl;
    return 0;
}

