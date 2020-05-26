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
    int n; cin >> n;
    vector<double> X(n), Y(n); rep(i, n) cin >> X[i] >> Y[i];

    vector<vector<double>> dist(n, vector<double>(n));
    rep(i, n){
        rep(j, n){
            dist[i][j] = sqrt(pow(X[i]-X[j], 2) + pow(Y[i]-Y[j], 2));
        }
    }
    
    vector<vector<int>> per;
    vector<int> array; rep(i, n) array.push_back(i);
    do{
        per.push_back(array);
    }while(next_permutation(all(array))); 

    double res = 0;
    for(vector<int> p: per){
        rep(i, p.size()-1){
            int v = p[i], nv = p[i+1];
            res += dist[v][nv];  
        }  
    }

    cout << fixed << setprecision(10);
    cout << res / per.size() << ln;
}
