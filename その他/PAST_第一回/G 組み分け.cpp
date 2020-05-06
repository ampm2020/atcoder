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

int n;
vector<vector<int>> groups; 
void make_group(vector<int> vc){
    if(vc.size() == n){
        groups.push_back(vc);
        return;
    }
    rep(i, 3){
        vc.push_back(i);
        make_group(vc);
        vc.pop_back();
    }
}

int main() {
    cin >> n;
    vector<vector<ll>> score(n, vector<ll>(n, 0));
    rep(i, n){
        for(int j = i + 1; j < n; j++){
            cin >> score[i][j];
        }
    }
    vector<int> vc;
    make_group(vc);

    ll mx = -INF;
    rep(i, groups.size()){
        vector<int>& g = groups[i];
        ll sum = 0;
        rep(j, n){
            for(int k=j+1; k<n; k++){
                if(g[j] == g[k]){
                    sum += score[j][k];
                }
            }
        }
        chmax(mx, sum);
    }
    cout << mx << ln;
}


