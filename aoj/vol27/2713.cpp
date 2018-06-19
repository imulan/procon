#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

const int N = 100010;
char op[N],var[N];

vector<int> G[N];

int X,Y;
int dfs(int v, int p, int dep, int val){
    int ret = 0;
    if(dep%2==1) ret = N;

    int ch = 0;
    for(int e:G[v])if(e!=p){
        ++ch;
        int xy = 0;
        if(var[e]=='X') xy=X;
        else xy=Y;

        int nv = val;
        if(op[e]=='&') nv &= xy;
        else if(op[e]=='|') nv |= xy;
        else nv ^= xy;

        if(dep%2==1) ret = min(ret, dfs(e,v,dep+1,nv));
        else ret = max(ret, dfs(e,v,dep+1,nv));
    }

    // printf(" %d :: %d, %d\n", v, ret,val);
    if(ch==0) return val;
    else return ret;
}

int main(){
    int n,m;
    cin >>n >>m;

    for(int i=1; i<n; ++i){
        string s;
        cin >>s;
        op[i] = s[3];
        var[i] = s[4];
    }

    rep(i,n-1){
        int u,v;
        cin >>u >>v;
        G[u].pb(v);
        G[v].pb(u);
    }

    vector<int> x(m),y(m),ans(m);
    map<vector<int>, vector<int>> q;
    rep(i,m){
        cin >>x[i] >>y[i];

        int ct[4]={};
        vector<int> vv;
        for(int j=15; j>=0; --j){
            int bx = x[i]>>j&1, by = y[i]>>j&1;
            int bb = bx*2+by;
            if(ct[bb]==0){
                vv.pb(bb);
                ++ct[bb];
            }
        }

        rep(j,4){
            if(ct[j]==0) vv.pb(j);
        }

        q[vv].pb(i);
    }

    vector<int> p(4);
    iota(all(p),0);

    do{
        X = 0;
        Y = 0;
        rep(i,4){
            if(p[i]>=2) X = 2*X + 1;
            else X = 2*X;
            if(p[i]%2==1) Y = 2*Y + 1;
            else Y = 2*Y;
        }

        int res = dfs(0,-1,0,0);

        int a[4]={};
        rep(i,4){
            int b = (res>>(3-i))&1;
            a[p[i]] = b;
        }

        for(int idx:q[p]){
            for(int j=15; j>=0; --j){
                int bx = x[idx]>>j&1, by = y[idx]>>j&1;
                int bb = bx*2+by;

                ans[idx] <<= 1;
                ans[idx] += a[bb];
            }
        }
    }while(next_permutation(all(p)));

    rep(i,m) cout << ans[i] << endl;
    return 0;
}
