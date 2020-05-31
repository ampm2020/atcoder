#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 998244353;
constexpr long long INF = 1000000009LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {   
    int menu[5]; rep(i, 5) cin >> menu[i];

    vector<int> index{0,1,2,3,4};
    int res = INF;
    do{
        int sum = 0;
        rep(i, 4){
            int time = menu[index[i]];
            sum += time;
            if(time%10 != 0) sum += 10 - (time%10);        
        }
        sum += menu[index[4]];
        chmin(res, sum);

    }while(next_permutation(all(index)));
    cout << res << ln;
}

