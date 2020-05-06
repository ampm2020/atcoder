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


int main() {
    int n, Q; cin >> n;
    ll min_odd = INF, min_even = INF, minus_odd = 0, minus_even = 0;
    vector<ll> C(n); 
    rep(i, n){
        cin >> C[i];
        if(i%2 == 0) chmin(min_odd, C[i]); //奇数
        else chmin(min_even, C[i]); //偶数
    }
    cin >> Q;

    ll sum = 0;
    rep(i, Q){
        int q; cin >> q;
        if(q == 1){
            int x, a; cin >> x >> a; x--;
            if(x%2 == 0){//紛らわしいがxが奇数のとき
                if(C[x] - minus_odd < a) continue; //在庫不足
                C[x] -= a; sum += a;
                chmin(min_odd, C[x] - minus_odd);
            }else{
                if(C[x] - minus_even < a) continue;
                C[x] -= a; sum += a;
                chmin(min_even, C[x] - minus_even);
            }

        }
        if(q == 2){
            int a; cin >> a;
            if(min_odd < a) continue; //いずれかの奇数カードが在庫不足
            minus_odd += a;
            min_odd -= a;
            sum += a * (n/2 + n%2);
        }
        if(q == 3){
            int a; cin >> a;
            if(min_odd < a || min_even < a) continue;
            minus_even += a; minus_odd += a;
            min_odd -= a, min_even -= a;
            sum += a * n;
        }
    }
    cout << sum << ln;
}





