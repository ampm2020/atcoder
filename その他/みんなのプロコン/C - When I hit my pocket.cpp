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
    ll k, a, b; cin >> k >> a >> b;
    ll res = 1;
    if(b <= a+2) res += k;//変換効率が悪いため、ひたすらビスケットを叩く
    else{
        //ビスケットをa枚まで増やす
        if(k < a-1) res += k;
        else{
            res += a-1;
            k -= a-1;
        }
        //ひたすらビスケットを変換する
        ll plus = b-a;
        res += k/2 * plus;
        //残り回数が奇数の場合、最後はビスケットを叩く
        if(k%2==1) res++;
    }
    cout << res << ln; 
}
