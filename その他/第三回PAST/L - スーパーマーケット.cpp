#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1001001001LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){ 
    int n; cin >> n; 
    vector<vector<int>> tana(n);//棚
    vector<ll> index(n, INF); 
    set<pii> fir, sec; //選択可能な商品の候補。pii = 消費期限/棚番号
    rep(i, n){
        int k; cin >> k;//商品の数
        rep(j, k){
            int t; cin >> t;
            tana[i].emplace_back(t);
            if(j==0){fir.insert({tana[i][0], i});}
            if(j==1){sec.insert({tana[i][1], i}); index[i] = 1;}
        }
        //番兵
        tana[i].emplace_back(-1);
        tana[i].emplace_back(-1);
    }
    int m; cin >> m;
    vector<int> ans(m);
    rep(i, m){
        int a; cin >> a;
        int val, num, select; //消費期限、棚番号、1or2
        if(a==1){
            pii buy = *fir.rbegin();
            val = buy.first, num = buy.second, select = 1;
        }else{
            pii buy1 = *fir.rbegin();
            pii buy2 = *sec.rbegin();
            if(buy1.first>buy2.first){
                val = buy1.first, num = buy1.second, select = 1;
            }else{
                val = buy2.first, num = buy2.second, select = 2;
            }
        }
        ans[i] = val;
        if(select == 2){
            sec.erase({val, num});
            index[num]++;
            if(index[num] >= tana[num].size())continue;//もう商品がない
            int next = tana[num][index[num]];
            sec.insert({next, num});
        }else{
            fir.erase({val, num});
            //2番目の商品を1番目に移動させ、棚から新商品を持ってくる
            if(index[num] >= tana[num].size())continue;//もう商品がない
            int sc = tana[num][index[num]];
            sec.erase({sc, num});
            fir.insert({sc, num});
            index[num]++; 
            if(index[num] >= tana[num].size())continue;
            int next = tana[num][index[num]];
            sec.insert({next, num});
        }
    }
    for(int res: ans) cout << res << ln; 
}

