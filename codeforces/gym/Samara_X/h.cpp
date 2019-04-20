#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define pb push_back

const int N = 1000;
int a[N][N];

const int INF = 1e9+7;

using pi = pair<int,int>;
using B = bitset<N>;

const pi NG(-1,-1);

int main(){
    int h,w;
    scanf(" %d %d", &h, &w);

    vector<int> ua;
    rep(i,h)rep(j,w){
        scanf(" %d", &a[i][j]);
        ua.pb(a[i][j]);
    }
    ua.pb(INF);

    sort(all(ua));
    ua.erase(unique(all(ua)), ua.end());
    int A = ua.size();

    auto check = [&](int idx){
        int val = ua[idx];
        vector<B> v(h);
        rep(i,h){
            rep(j,w){
                if(a[i][j]>=val) v[i].set(j);
            }
        }

        rep(i,h){
            B c;
            rep(j,h)if(i!=j) c |= v[j];
            if(c.count()<=1){
                int rw = 0;
                rep(j,w){
                    if(c[j]) rw = j;
                }
                return pi(i,rw);
            }
        }
        return NG;
    };

    int ng=0, ok=A-1;
    while(ok-ng>1){
        int mid = (ok+ng)/2;
        pi res = check(mid);
        if(res == NG) ng = mid;
        else ok = mid;
    }

    pi ans = check(ok);
    printf("%d %d\n", ans.fi+1, ans.se+1);
    return 0;
}