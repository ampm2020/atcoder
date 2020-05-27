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

vector<vector<char>> OP;
int len;

void func(vector<char> op){
    if(op.size() == len-1){
        OP.push_back(op);
        return;
    }

    op.push_back('+');
    func(op);
    op.pop_back();

    op.push_back('&');
    func(op);
}

int main(){
    string s; cin >> s;
    len = s.size();
    vector<char> v; 
    func(v);
    
    ll res = 0;
    if(OP.empty()) res = stoi(s);
    for(vector<char> op: OP){
        ll sum = 0, num = s[0] - '0';
        rep(i, op.size()){
            if(op[i] == '+'){
                sum += num; num = s[i+1] - '0';
            }else{
                num = num*10 + s[i+1] - '0';
            }
        }
        res += sum + num;
    }

    cout << res << ln;
}
