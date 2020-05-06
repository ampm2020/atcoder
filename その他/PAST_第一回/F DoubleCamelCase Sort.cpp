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
    string s, t = ""; cin >> s;
    priority_queue<string, vector<string>, greater<string>> que;
    int cnt = 0;

    rep(i, s.length()){
        t.push_back(s[i]);
        if(isupper(s[i])) cnt++;
        if(cnt >= 2){
            cnt = 0;
            if(t[0] >= 'A' && t[0] <= 'Z') t[0] += 32;
            if(t[t.size()-1] >= 'A' && t[t.size()-1] <= 'Z') t[t.size()-1] += 32;           
            que.push(t);
            t = "";
        }
    }
    while(!que.empty()){
        string res = que.top();  que.pop();
        res[0] -= 32; res[res.size() -1] -= 32;
        cout << res;
      
    }
    cout << ln;
}




