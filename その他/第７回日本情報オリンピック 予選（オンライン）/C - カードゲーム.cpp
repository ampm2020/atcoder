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
    int n; cin >> n;
    vector<int> handA(n), handB;
    rep(i, n) cin >> handA[i];
    for(int i=1; i<=2*n; i++){
        auto iter = find(all(handA), i);
        if(iter == handA.end()) handB.push_back(i);
    }
    sort(all(handA)); sort(all(handB));

    int fieldcard = 0; bool is_a = true;
    while(!handA.empty() && !handB.empty()){
        vector<int>& hand = is_a ? handA : handB;

        auto iter = upper_bound(all(hand), fieldcard);
        if(iter != hand.end()){
            fieldcard = *iter;
            int index = distance(hand.begin(), iter);
            hand.erase(hand.begin()+index);        
        }else{
            fieldcard = 0;
        }
        
        if(is_a) is_a = false;
        else is_a = true;
    }   
    cout << handB.size() << ln;
    cout << handA.size() << ln;
}
