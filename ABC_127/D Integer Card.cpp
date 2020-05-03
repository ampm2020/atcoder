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

int main(){
    int n, m;
    cin >> n >> m;
    priority_queue<ll, vector<ll>, greater<ll>> que;
    rep(i, n){
        ll a; cin >> a;
        que.push(a);
    }
    vector<pll> vc;
    rep(i, m){
        ll b, c; cin >> b >> c;
        vc.push_back(pii(c, b));
    }
    sort(all(vc), greater<pll>());

    rep(i, m){
        int b = vc[i].second, c = vc[i].first;
        rep(j, b){
            int num = que.top(); 
            if(num < c) { que.pop(); que.push(c); }
            else break; 
        }
    }

    ll sum = 0;
    rep(i, n){
        sum += que.top(); que.pop();
    }
    cout << sum << ln;
}
