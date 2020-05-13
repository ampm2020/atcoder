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



int main() {
    int n; ll k; cin >> n >> k;
    vector<int> A(n);
    rep(i, n) cin >> A[i], A[i]--;

    vector<int> first_visited(200200, -1); //その町に最初に訪れた時にテレポーターを使った回数
    first_visited[0] = 0;
    vector<int> pass; pass.push_back(0); //同じ町に二度訪れるまでの経路

    //ループが始まるまでの経路を作成
    //rp:　pass内の閉路の長さ 　nrp: 閉路でない経路の長さ  cur: 現在地
    int rp = 0, nrp = 0, cur = 0; 
    for(int cnt=1; cnt<=k; cnt++){
        int to = A[cur]; 
        if(first_visited[to] == -1){ //次の街をまだ訪れていない場合は経路を追加してそこに移動する
            pass.push_back(to);
            first_visited[to] = cnt;
            cur = to;
        }else{ //同じ町を二度訪れる場合はループ終了 
            rp = cnt - first_visited[to];
            nrp = pass.size() - rp;
            break;
        }
    }
    if(rp == 0) rp = pass.size(); //閉路を見つける前にループが終わった場合の処理

    int ans = nrp + (k - nrp) % rp;
    cout << pass[ans] + 1 << ln;
}

