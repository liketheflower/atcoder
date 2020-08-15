#include<iostream>
using namespace std;
int main()
{
    
    /*void print_I_love_world()
    {
        cout<<"I love world"<<endl;
        return;
    }
    */
    function<void(void)> print_I_love_world = []()
    {
        cout<<"I love world"<<endl;
        return; 
    };
    print_I_love_world();
    cout<<"Hello world"<<endl;
    return 0;
}

