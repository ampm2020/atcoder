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

    set<int> st{-1, 0, n+1, n+2};
    ll ans = 0;
    for(int i=n; i>0; i--){
        auto iter = st.lower_bound(place[i]);
        ll r1 = *iter, r2 = *(++iter); --iter;
        ll l1 = *(--iter), l2 = *(--iter);
        //cout << l2 << " " << l1 << " " << r1 << " " << r2 << ln;
        if(r1 != n+1) ans += i * (place[i]-l1) * (r2-r1);
        if(l1 != 0) ans += i * (l1-l2) * (r1-place[i]);
        //cout << "ans:" << ans << ln;
        st.insert(place[i]);
    }
    cout << ans << ln;
}

    