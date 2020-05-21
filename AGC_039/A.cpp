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


int main(){ 
    string s; int k; cin >> s >> k;
    string two = s + s;
    string two_ = s + s + s;
    ll a = 0, b = 0, c = 0;
    rep(i, s.size()-1){
        if(s[i] == s[i+1]){
            a++;
            i++;
        }
    }
    rep(i, two.size()-1){
        if(two[i] == two[i+1]){
            b++;
            i++;
        }
    }
    rep(i, two_.size()-1){
        if(two_[i] == two_[i+1]){
            c++;
            i++;
        }
    }
    c -= a;
    ll res;
    if(k%2==0){
        res = b + (k-2)/2 * c;
    }
    else{
        res = a + (k-1)/ 2 * c;
    } 
    cout << res << ln;
}