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
    int n, sum = 0;
    cin >> n;
    vector<int> number(n);
    rep(i, n) {cin >> number[i]; sum += number[i]; }

    int res = 0;
    if(sum % n != 0) res = -1;
    else{
        int m = sum / n, island = 1, cnt = 0;
        rep(i, n){
            cnt += number[i];
            if(cnt == island * m){
                res += island - 1;
                island = 1;
                cnt = 0;
            }else{
                island++;
            }
        }
    }
    cout << res << ln;
}