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

int main() {
    int n; cin >> n;
    vector<int> A(n); rep(i, n) cin >> A[i];
    sort(all(A));
    
    int a, b = n, bef = 0; bool change = false;
    set<int> st;
    rep(i, n){
        int siz = st.size();
        st.insert(A[i]);
        if(st.size() == siz){
            change = true;
            a = A[i];
        }
        if(A[i] == bef + 2){
            change = true;
            b = A[i]-1;
        }
        bef = A[i];
    }

    if(change) cout << a << " " << b << ln;
    else cout << "Correct" << ln;
}






