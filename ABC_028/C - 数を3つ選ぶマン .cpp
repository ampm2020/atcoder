#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long INF = 1000000009LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
    int num[5];
    rep(i, 5) cin >> num[i];

    priority_queue<int> que;
    for(int i=0; i <=2; i++){
        for(int j=i+1; j<=3; j++){
            for(int k=j+1; k<=4; k++){
                int n = num[i]+num[j]+num[k];
                que.push(n);
            }
        }
    }
    set<int> st;
    while(!que.empty()){
        int n = que.top(); que.pop();
        st.insert(n);
        if(st.size() == 3){
            cout << n << ln;
            break;
        }
    }
}
