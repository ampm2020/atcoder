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
   string s; cin >> s;
   int len  = s.size();
   s += "DDD";
   
   ll res = 0; ll zero = 0; bool mode = false;
   rep(i, len){
       if(mode){
         if(s[i] == 'A') zero++;
         else if(s[i] == 'B' && s[i+1] == 'C'){
             res += zero; i++;
         }else{
             zero = 0; mode = false;
         }
       }else{
           if(s[i] == 'A') zero++, mode = true;
       }
   }
   cout << res << ln;
}