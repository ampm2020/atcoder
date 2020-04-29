#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000000LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

bool flag;
string S;
int len;
vector<bool> sign;

void func(int n){
    if(n == len){
        flag = true;
        return;
    }

    rep(i, 4){
        string a;
        if(i == 0) a = "dream";  if(i == 1) a = "dreamer";
        if(i == 2) a = "erase";  if(i == 3) a = "eraser";
        int al = a.size();
        //cout <<"len:" << len << " n+al:" << n+al << ln;
        if(n + al > len) continue;
        bool same = false;
        string s;
        rep(j, al){
            s += S[n + j];
        }
        if(s == a) same = true;
        //cout << "s:" << s << " a:" << a << ln;
        if(same &&!sign[n + al]){
            func(n + al);
            sign[n + al] = true;
        }
    }
}

int main() {
    cin >> S;
    len = S.size();
    flag = false;
    sign.resize(len + 10);

    func(0);

    if(flag) cout << "YES" << ln;
    else cout << "NO" << ln;
}
    
