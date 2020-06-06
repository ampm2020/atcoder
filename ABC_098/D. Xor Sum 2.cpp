#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000009LL;
constexpr long long LINF = 1000100010001000100LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() { 
    int n; cin >> n;
    vector<ll> A(n);
    rep(i, n) cin >> A[i];

    ll res = 0, sum = 0; int right = 0;
    for(int left = 0; left < n; left++){
        while(right < n){
            ll tmp = sum^A[right];
            if(sum+A[right] != tmp) break;
            sum += A[right];
            right++;
        }
        res += (ll)(right - left);

        sum -= A[left];
    }
    cout << res << ln;
}