#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000009LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define fo(i,j,n) for (int i=(j); i < (n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    int n; cin >> n;
    vector<ll> place(n+1); //各番号の位置を示す
    fo(i, 1, n+1){
        int a; cin >> a; place[a] = i; //数aはi番目に出現する
    }

    set<int> st{0, n+1};
    ll ans = 0;
    fo(i, 1, n+1){
        auto iter = st.lower_bound(place[i]);
        int r = *iter;
        int l = *(--iter);
        ans += i * (place[i] - l) * (r - place[i]);
        st.insert(place[i]);
    }
    cout << ans << ln;
}

    