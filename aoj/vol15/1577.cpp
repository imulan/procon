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
vector<int> G[N];

int par[N];
void dfs(int x){
    for(int e:G[x])if(e!=par[x]){
        par[e] = x;
        dfs(e);
    }
}

bool b[N]={};
int vis[N]={};

bool solve(){
    int n,u,v;
    scanf(" %d %d %d", &n, &u, &v);
    --u;
    --v;
    rep(i,n-1){
        int x,y;
        scanf(" %d %d", &x, &y);
        --x;
        --y;
        G[x].pb(y);
        G[y].pb(x);
    }

    // if(n%2==1) return false;

    par[u] = -1;
    dfs(u);

    int tt = v;
    while(tt!=u){
        b[tt] = true;
        tt = par[tt];
    }

    int R=1, B=1;
    vis[u] = 1;
    vis[v] = 2;

    int now = u;
    while(R<n/2){
        int ch=0;
        for(int e:G[now])if(par[now]!=e && !vis[e]) ++ch;

        if(ch==0) break;
        else if(ch==1){
            for(int e:G[now])if(par[now]!=e && !vis[e]){
                ++R;
                vis[e] = 1;
                now = e;
            }
        }
        else if(ch==2){
            for(int e:G[now])if(par[now]!=e && !vis[e]){
                if(!b[e]){
                    ++R;
                    vis[e] = 1;
                    now = e;
                    break;
                }
            }
        }
        else return false;
    }

    while(B<n/2){
        int ct = 0;
        for(int e:G[v])if(vis[e]==0) ++ct;
        if(ct==0) break;
        if(ct>=2) return false;

        for(int e:G[v])if(vis[e]==0){
            ++B;
            vis[e] = 2;
            v = e;
        }
    }

    rep(i,n)if(vis[i]==0) return false;
    return R==B;
}

int main(){
    cout << (solve()?"Yes":"No") << endl;
    return 0;
}
