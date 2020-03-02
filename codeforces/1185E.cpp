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

using pi = pair<int,int>;
using P = pair<pi,pi>;

const P NG = {{-1,-1},{-1,-1}};

void OUT(P p){
    vector<int> v({p.fi.fi, p.fi.se, p.se.fi, p.se.se});
    rep(i,4) printf("%d%c", v[i]+1, " \n"[i==3]);
}

// -1:NO, 0:horizontal, 1:vertical
int can_snake(const vector<pi> &v){
    pi p = v[0];
    bool hr = true, vt = true;
    for(const auto &q:v){
        if(p.fi != q.fi) hr = false;
        if(p.se != q.se) vt = false;
    }

    if(hr) return 0;
    if(vt) return 1;
    return -1;
}

void solve(){
    int h,w;
    scanf(" %d %d", &h, &w);

    vector<vector<int>> f(h,vector<int>(w,-1));
    int n = 0;
    rep(i,h){
        char s[2020];
        scanf(" %s", s);
        rep(j,w){
            if(islower(s[j])) f[i][j] = s[j]-'a';
            n = max(n,f[i][j]+1);
        }
    }

    vector<vector<pi>> visible(n);
    rep(i,h)rep(j,w)if(f[i][j]>=0) visible[f[i][j]].pb({i,j});

    auto make_snake = [&](int a){
        if(visible[a].empty()){
            pi p = visible[n-1].front();
            return P(p,p);
        }

        int ch = can_snake(visible[a]);
        if(ch==-1) return NG;

        pi L = visible[a].front(), R = visible[a].back();
        if(ch==0){
            int y = L.fi;
            int l = L.se, r = R.se;
            for(int x=l; x<=r; ++x){
                if(f[y][x] < a) return NG;
            }
        }
        else{
            int x = L.se;
            int l = L.fi, r = R.fi;
            for(int y=l; y<=r; ++y){
                if(f[y][x] < a) return NG;
            }
        }
        return P(L,R);
    };

    vector<P> ans(n);
    for(int i=n-1; i>=0; --i){
        P res = make_snake(i);
        if(res == NG){
            printf("NO\n");
            return;
        }
        ans[i] = res;
    }

    printf("YES\n%d\n", n);
    rep(i,n) OUT(ans[i]);
}

int main(){
    int T;
    scanf(" %d", &T);
    while(T--) solve();
    return 0;
}
