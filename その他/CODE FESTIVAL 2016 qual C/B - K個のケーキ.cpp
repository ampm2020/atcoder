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
    int k, t; cin >> k >> t;
    vector<pii> cake; 
    rep(i, t){
        int a; cin >> a;
        cake.emplace_back(a, i); //i番目のケーキがa個ある
    }

    int res = 0;
    vector<int> eat(k, -1);//食べたケーキ
    rep(i, k){
        sort(all(cake), greater<pii>());
        if(i>0 && eat[i-1] == cake[0].second){//同じケーキを食べそうになった場合
            if(cake.size() > 1 && cake[1].first > 0){//他に食べられそうなケーキがあれば        
                eat[i] = cake[1].second;
                cake[1].first--;
            }else{
                eat[i] = cake[0].second;
                cake[0].first--;
            }
        }else{
            eat[i] = cake[0].second;
            cake[0].first--;
        }
        if(i>0 && eat[i] == eat[i-1]) res++;
    }
    cout << res << ln;
}