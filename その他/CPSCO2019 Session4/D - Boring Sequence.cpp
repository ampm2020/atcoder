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
    int n, k; cin >> n >> k;
    vector<int> A(n); rep(i, n) cin >> A[i];

    int ng = 0, ok = 200001;
    while(ok - ng > 1){
        int mid = (ok + ng) / 2, last = -1, con = 0, cnt = 0;
        rep(i, n){
            if(A[i] == last) con++;
            else con = 1;
            last = A[i];
            if(con > mid) cnt++, last = -1;
        }
        if(cnt <= k) ok = mid;
        else ng = mid;
    }
    cout << ok << ln;
} 
