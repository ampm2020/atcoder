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
    int na, nb; cin >> na >> nb;
    set<int> st;
    map<int, bool> mp_a, mp_b;
    rep(i, na){
        int a; cin >> a;
        st.insert(a);
        mp_a[a] = true;
    }
    rep(i, nb){
        int b; cin >> b;
        st.insert(b);
        mp_b[b] = true;
    }
    int cnt = 0;
    for(auto ma: mp_a){
        int num = ma.first;
        if(mp_b[num] == true) cnt++;
    }
    cout << fixed << setprecision(10);
    cout << cnt / (double)st.size() << ln;
} 