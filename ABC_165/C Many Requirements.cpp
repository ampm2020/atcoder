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

int n, m, q;
vector<vector<int>> vec;

void func(vector<int> vc, int num){
    if(num == n) {
        vec.push_back(vc);
        return;
    }
    for(int i = vc[vc.size()- 1]; i <= m; i++){
        vector<int> vc2 = vc;
        vc2.push_back(i);
        func(vc2, num + 1);
    }
}

int main(){
    cin >> n >> m >> q;
    vector<int> a(q),b(q),c(q),d(q), vc;
    rep(i, q) cin >> a[i] >> b[i] >> c[i] >> d[i];

    vc.push_back(1);
    func(vc, 1);
        
    int mx = 0;
    rep(i, vec.size()){
        vector<int> v = vec[i];
        int score = 0;
        rep(j, q){
            if(v[b[j]-1] - v[a[j]-1] == c[j]){
                score += d[j];
            }
        }
        chmax(mx,score);       
    }
    cout << mx << ln;
}
