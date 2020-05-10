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
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



int main() {
    ll n, k; cin >> n >> k;
    vector<ll> A(n+10); A.push_back(-1);
    rep(i, n) cin >> A[i+1];

    vector<ll> visited(200200, -1);
    visited[1] = 0;
    vector<ll> pass; pass.push_back(1);

    ll rp = 0, nrp = 0, cur = 1;
    for(ll i=1; i<=n; i++){
        if(i > k) break;
        ll next = A[cur];
        if(visited[next] == -1){
            pass.push_back(next);
            visited[next] = i;
            cur = next;
        }else{
            rp = i - visited[next];
            nrp = pass.size() - rp;
            break;
        }
    }
    if(rp == 0) rp = pass.size();
    ll x = (k - nrp) % rp;
    cout << pass[nrp + x] << ln;
}
