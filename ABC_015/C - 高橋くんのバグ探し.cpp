#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000009LL;
constexpr long long LINF = 1000100010001000100LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int n, k;
bool zero = false;

void judge(int m, int cnt, vector<vector<int>>& Q){
    if(cnt == n){
        if(m == 0)zero = true;
        return;
    }

    rep(i, k){
        int tmp =  m ^ Q[cnt][i];
        judge(tmp, cnt+1, Q);
    }
}

int main(){ 
    cin >> n >> k;
    vector<vector<int>> Q(n);
    rep(i, n){
        rep(j, k){
            int a; cin >> a;
            Q[i].push_back(a);
        }
    }

    judge(0, 0, Q);
    cout << (zero ? "Found" : "Nothing") << ln;
} 