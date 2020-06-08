#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000009LL;
constexpr long long LINF = 1000100010001000100LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){ 
    map<int, int> conversion;
    rep(i,10){
        int b; cin >> b;
        conversion[b] = i;
    }

    int n; cin >> n;
    vector<pii> A(n);
    rep(i, n){
        string s; cin >> s;
        int num = 0, len = s.size();
        rep(j, len){
            int tmp = (conversion[s[j] - '0']) * pow(10, len-1-j);
            num += tmp;
        }
        A[i] = {num, stoi(s)};
    }
    sort(all(A));

    for(auto res: A){
        cout << res.second << ln;
    }
} 