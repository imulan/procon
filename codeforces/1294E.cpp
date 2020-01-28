#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

int main(){
    int h,w;
    scanf(" %d %d", &h, &w);

    vector<vector<int>> a(h, vector<int>(w));
    rep(i,h)rep(j,w){
        scanf(" %d", &a[i][j]);
        --a[i][j];
    }

    int ans = 0;
    rep(col,w){
        map<int,int> pos;
        rep(i,h){
            int idx = i*w+col;
            pos[idx] = i;
        }

        vector<int> ct(h);
        rep(i,h){
            int v = a[i][col];
            if(pos.count(v)){
                int p = pos[v];

                int t = i;
                if(t < p) t += h;
                ++ct[t-p];
            }
        }

        int add = 1919191;
        rep(i,h){
            int cost = i+h-ct[i];
            add = min(add, cost);
        }
        ans += add;
    }

    printf("%d\n", ans);
    return 0;
}
