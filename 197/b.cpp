#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
        int R, C, y, x;
        string this_s;
        vector<string> s;
    void inputs(){
        cin >> R >> C >> y >> x;
        s.reserve(R);
        while (R--){
             cin << this_s; 
             s.push_back(this_s);
        }
    }
    void solve(){
        int ret = 1;
        if (s[y][x] == '#') {
             cout << ret <<endl;
             return;
        }
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
