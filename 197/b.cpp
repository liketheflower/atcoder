#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
    public:
        int R, C, y, x;
        string this_s;
        vector<string> s;
    void inputs(){
        cin >> R >> C >> y >> x;
        y--; x--;
        s.reserve(R);
        for (int i = 0; i < R; ++i){
             cin >> this_s; 
             s.push_back(this_s);
        }
    }
    void solve(){
        int ret = 0;
        if (s[y][x] == '#') {
             cout << ret <<endl;
             return;
        }
        ret = 1;
        for (int i=y-1; i >=0; --i) {
             if (s[i][x] == '.') ret++;
             else break;
        }
        for (int i=y+1; i <R; ++i) {
             if (s[i][x] == '.') ret++;
             else break;
        }
        for (int j=x-1; j >=0; --j) {
             if (s[y][j] == '.') ret++;
             else break;
        }
        for (int j=x+1; j < C; ++j) {
             if (s[y][j] == '.') ret++;
             else break;
        }
        cout << ret << endl;
    }

};

int main(){
  Solution sol;
  sol.inputs();
  sol.solve();
  return 0;
}
