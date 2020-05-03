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

int main(){
    int n, m;
    cin >> n >> m;
    vector<pii> res;
    set<int> st;
    
    int a = 1, b = n;
    rep(i, m){
        int siz = st.size();
        st.insert(b-a);
        st.insert(n+a-b);
        if(st.size() != siz + 2) b--;
        res.push_back(pii(a, b));
        a++; b--;
    }
    rep(i, m){
        cout << res[i].first << " " << res[i].second << ln;
    }

}

