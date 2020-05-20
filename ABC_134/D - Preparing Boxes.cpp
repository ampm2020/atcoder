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
    vector<int> A(n+1); rep(i, n) cin >> A[i+1];
    vector<int> res(n+1);

    int one = 0;
    for(int num=n; num>0; num--){
        int cnt = 0;
        for(int i=num*2; i<=n; i += num){
            if(res[i]) cnt++;
        }
        if(cnt%2==1 && A[num]==0 || cnt%2==0 && A[num]==1) res[num] = 1, one++;
        else res[num] = 0;
    }
    
    cout << one << ln;
    for(int i=1; i<=n; i++){
        if(res[i]) cout << i << ln;
    }
}