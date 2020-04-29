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

int vector_finder(vector<char> vec, char number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return 1;
  }
  else { // 発見できなかったとき
    return 0;
  }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<char> ng(k);
    rep(i, k) cin >> ng[i];

    bool f = false;
    while(!f){
        f = true;
        string s = to_string(n);
        rep(i, s.size()){
            char c = s[i];
            if(vector_finder(ng, c)){
                f = false;
                break;
            } 
        }
        if(!f) n++;
    }
    cout << n << ln;
}
    
