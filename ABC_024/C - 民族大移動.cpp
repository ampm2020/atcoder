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
#define fo(i,j,n) for (int i=(j); i < (n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



int main(){ 
    int N, D, K; cin >> N >> D >> K;
    vector<pii> LR(D);
    rep(i, D){
        int l, r; cin >> l >> r;
        LR[i] = {l, r};
    }
    vector<int> S(K), T(K);
    vector<bool> is_r(K); //民族iの移動方向 true:右, false:左 
    rep(i, K){
        cin >> S[i] >> T[i];
        if(S[i] < T[i]) is_r[i] = true; else is_r[i] = false;
    }

    vector<int> res(K, -1);
    rep(i, D){
        int L = LR[i].first, R = LR[i].second;
        rep(j, K){ //民族移動
            if(S[j] < L || S[j] > R) continue; //移動可能区域にいない場合は何もしない
            if(is_r[j] && res[j] == -1){//右に移動
                S[j] = R;
                if(S[j] >= T[j]) res[j] = i+1;
            }else if(!is_r[j] && res[j] == -1){
                S[j] = L;
                if(S[j] <= T[j]) res[j] = i+1;
            }
        }
    }
    rep(i, K){
        cout << res[i] << ln;
    }
}