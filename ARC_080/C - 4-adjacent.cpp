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


int main(){
    int n; cin >> n;
    map<int, int> mp;
    rep(i, n){
        int a; cin >> a;
        if(a%4==0) mp[2]++;
        else if(a%2==0) mp[1]++;
        else mp[0]++;
    }
    bool fg = true;
    int num = 2;
    rep(i, n){
        if(num == 0){
            if(mp[2]>0){mp[2]--; num = 2;}
            else{fg = false; break;}
        }else if(num == 1){
            if(mp[1]>0){mp[1]--; num = 1;}
            else if(mp[2] > 0){mp[2]--; num = 2;}
            else {fg = false; break;}
        }else{
            if(mp[0]>0){mp[0]--; num = 0;}
            else if(mp[1]>0){mp[1]--; num = 1;}
            else if(mp[2] > 0){mp[2]--; num = 2;}
        }
    }
    if(fg) cout << "Yes" << ln;
    else cout << "No" << ln;
}
