#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

using pi = pair<int,int>;

const int N = 1000000;
int v[2][N];

int main(){
    int n;
    scanf(" %d", &n);

    vector<int> w;
    rep(i,2)rep(j,n){
        scanf(" %d", &v[i][j]);
        w.pb(v[i][j]);
    }
    w.pb(0);
    sort(all(w));
    w.erase(unique(all(w)),w.end());
    int W = w.size();

    auto check = [&](int mid){
        int ww = w[mid];
        rep(i,2){
            int now = 0;
            rep(j,n){
                if(v[i][j]<=ww) continue;

                if(now == 0) now = v[i][j];
                else{
                    if(now != v[i][j]) return false;
                    now = 0;
                }
            }

            if(now != 0) return false;
        }
        return true;
    };

    int ok = W-1, ng = -1;
    while(ok-ng>1){
        int mid = (ok+ng)/2;
//        remove w[mid] lighter
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    printf("%d\n", w[ok]);

    return 0;
}