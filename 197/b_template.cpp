#include <iostream>
#include <iosfwd>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cassert>
#include <cctype>
#include <climits>
#include <vector>
#include <bitset>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <deque>
#include <string>
#include <list>
#include <iterator>
#include <sstream>
#include <complex>
#include <fstream>
#include <functional>
#include <numeric>
#include <utility>
#include <algorithm>

using namespace std;

// MACROS_BEGIN
#define CLEAR() cerr << endl;
#define LET(x, a) __typeof(a) x = a
#define FOREACH(it, v) for (LET(it, (v).begin()); it != (v).end(); ++it)
#define REPEAT(i, n) for (int i = 0; i < (n); ++i)
// MACROS_END

// GENERIC_UTILITIES_BEGIN
template <class T> inline int size(const T& c) {return (int) c.size();}
inline long long two(int x) {return (1LL << (x));}

vector<string> split(string s, string delim) {
    s += delim[0];
    string tmp;
    vector<string> result;
    for (int i = 0; i < size(s); ++i) {
        if (delim.find(s[i]) == string::npos) {
            tmp.push_back(s[i]);
        }
        else {
            if (tmp != "") result.push_back(tmp);
            tmp.clear();
        }
    }
    return result;
}
// GENERIC_UTILITIES_END

// FAST_IO_BEGIN
// FAST_IO_END

// STANDARD_IO_BEGIN
#ifndef USING_FAST_IO
int readInt() {int N = -1; scanf("%d", &N); return N;}
double readDouble() {double D; scanf("%lf", &D); return D;}
string readString() {char buffer[1 << 20]; scanf("%s", buffer); return buffer;}
long long readLongLong() {long long N = -1; scanf("%lld", &N); return N;}
#endif // NOT DEFINED USING_FAST_IO
// STANDARD_IO_END


// OUTPUT_UTILITIES_BEGIN
template <class A, class B> ostream& operator << (ostream& o, const pair<A, B>& p);
template <class T> ostream& operator << (ostream& o, const vector<T>& v);
template <class A, class B> ostream& operator << (ostream& o, const map<A, B>& m);
template <class T> ostream& operator << (ostream& o, const set<T>& s);
template <class T> ostream& operator << (ostream& o, const queue<T>& q);
template <class T> ostream& operator << (ostream& o, const stack<T>& s);

template <class A, class B> ostream& operator << (ostream& o, const pair<A, B>& p) {
    o << "(" << p.first << "," << p.second << ")"; return o;
}

template <class T> ostream& operator << (ostream& o, const vector<T>& v) {
    o << "{"; bool first = true; FOREACH(it, v) { if (!first) o << ","; first = false; o << *it; } return o << "}";
}

template <class A, class B> ostream& operator << (ostream& o, const map<A, B>& m) {
    o << "{"; bool first = true; FOREACH(it, m) { if (!first) o << ","; first = false; o << *it; } return o << "}";
}

template <class T> ostream& operator << (ostream& o, const set<T>& s) {
    o << "{"; bool first = true; FOREACH(it, s) { if (!first) o << ","; first = false; o << *it; } return o << "}";
}

template <class T> ostream& operator << (ostream& o, const queue<T>& q) {
    o << "{"; bool first = true; queue<T> p = q; while (!p.empty()) { if (!first) o << ","; first = false; o << p.front(); p.pop(); } return o << "}";
}

template <class T> ostream& operator << (ostream& o, const stack<T>& s) {
    o << "{"; bool first = true; stack<T> r = s; while (!r.empty()) { if (!first) o << ","; first = false; o << r.top(); r.pop(); } return o << "}";
}
// OUTPUT_UTILITIES_END

// DEBUGGING_UTILITIES_BEGIN
// DEBUGGING SWITCH
#define PHOENIX_DEBUG

#ifdef PHOENIX_DEBUG
#define BUG(x) cerr << __LINE__ << ": " << #x << " = " << x << endl;
#else
#define BUG(...)
#endif
// DEBUGGING_UTILITIES_END

const double epsilon = 1e-8;
const int infinite    = 2000000000; // 2 * 10^9
const long long infiniteLL = 2000000000000000000LL; // 2 * 10^18
const long long modulo = 1000000007;

struct Task {
    int N, ;
    vector<int> color;
    vector< vector<int> > adj;
    vector<int> subtreeSize;
    vector<int> count;
    vector<long long> answer;
    int visited;

    void readInput() {
        N = readInt();
        adj.resize(N);
        color.resize(N);

        for (int i = 0; i < N; ++i) {
            color[i] = readInt() - 1;
        }

        for (int i = 0; i < N - 1; ++i) {
            int u = readInt() - 1, v = readInt() - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        subtreeSize.resize(N, 0);
        count.resize(N, 0);
        answer.resize(N, countPaths(N));
        visited = 0;
    }

    long long countPaths(int K) {
        return K + (K * (K - 1)) / 2;
    }

    void subSelf(long long& result, long long K) {
        result -= countPaths(K);
    }

    void dfs(int u, int p) {
        subtreeSize[u] = 1;
        int c = color[u];
        int before = count[c];

        for (int v : adj[u]) {
            if (v == p) {
                continue;
            }

            int prev = visited - count[c];
            dfs(v, u);
            subtreeSize[u] += subtreeSize[v];
            int next = visited - count[c];

            subSelf(answer[c], next - prev);
        }

        ++visited;
        count[c] = before + subtreeSize[u];
    }

    void solve() {
        dfs(0, -1);

        for (int i = 0; i < N; ++i) {
            subSelf(answer[i], N - count[i]);
        }

        for (int i = 0; i < N; ++i) {
            cout << answer[i] << endl;
        }
    }

    void perform() {
        readInput();
        solve();
    }
};

int main()
{
    Task task;
    task.perform();

    return 0;
}


