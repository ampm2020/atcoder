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
    int n, k;
    cin >> n >> k;
    vector<ll> V(n);
    rep(i, n) cin >> V[i];

    ll res = 0;
    rep(i, k+1){
        rep(j, k+1){
            if(i+j > k || i+j > n) continue;
            cout << "i:" << i << " j:" << j;
            vector<ll> jewel;
            ll sum = 0;
            rep(a, i){
                jewel.push_back(V[i]);
                cout << " sum+:" << V[i];
                sum += V[i];
            }
            rep(b, j){
                jewel.push_back(V[n-1-b]);
                sum += V[n-1-b];
                cout << " sum+:" << V[i];
            }
            sort(all(jewel));
            rep(c, min((int)jewel.size(), k-(i+j))){
                if(jewel[c] < 0)sum -= jewel[c];
            }
            cout << " sum:" << sum << ln;
        chmax(res, sum);
        }
    }
    cout << res << ln;
}
