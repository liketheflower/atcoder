#include<iostream>
using namespace std;

void solve(){
    string s;
    cin >> s;
    string ret;
    ret = s.substr(1) + s[0];
    cout << ret << endl;
}

int main(){
    solve();
    return 0;
}
