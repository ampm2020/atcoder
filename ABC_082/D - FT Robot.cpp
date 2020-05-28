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
    string s; int x, y; cin >> s >> x >> y;
    vector<int> mX, mY;
    
    int cnt = 0; int cx = 0, cy = 0;
    for(char c: s){
        if(c == 'F') cnt%2 ? cy++ : cx++;
        else{
            if(cnt%2==0){
                mX.push_back(cx);
                cx = 0;
            }else{
                mY.push_back(cy);
                cy = 0;
            }
            cnt++;
        }
    }
    if(cnt%2==0) mX.push_back(cx);
    else mY.push_back(cy);
    
    map<int, bool> dpx, dpy;
    dpx[0] = true, dpy[0] = true; bool fir = true;
    for(int num: mX){
        vector<int> key;
        for(auto m: dpx)key.push_back(m.first);
        dpx.clear();
        for(int m: key){
            dpx[m+num] = true;
            if(!fir) dpx[m-num] = true;
        }
        fir = false;
    }
    for(int num: mY){
        vector<int> key;
        for(auto m: dpy)key.push_back(m.first);
        dpy.clear();
        for(int m: key){
            dpy[m+num] = true;
            dpy[m-num] = true; 
        }  
    }

    if(dpx[x] && dpy[y]) cout << "Yes" << ln;
    else cout << "No" << ln;
}
