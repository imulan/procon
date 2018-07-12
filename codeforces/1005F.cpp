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

using pi = pair<int,int>;

const int N = 200002;
vector<int> G[N];

int main(){
    int n,m,k;
    scanf(" %d %d %d", &n, &m, &k);

    vector<pi> e(m);
    map<pi,int> e2id;
    rep(i,m){
        int a,b;
        scanf(" %d %d", &a, &b);
        --a;
        --b;
        if(a>b) swap(a,b);

        G[a].pb(b);
        G[b].pb(a);
        e[i] = {a,b};
        e2id[e[i]] = i;
    }

    vector<int> par(n,-1);
    vector<int> d(n,n);
    d[0] = 0;
    queue<int> que;
    que.push(0);
    while(!que.empty()){
        int v = que.front();
        que.pop();
        for(int nx:G[v]){
            if(d[nx] > d[v]+1){
                d[nx] = d[v]+1;
                par[nx] = v;
                que.push(nx);
            }
        }
    }

    string t(m,'0');
    for(int i=1; i<n; ++i){
        int u=i, v=par[i];
        if(u>v) swap(u,v);
        t[e2id[{u,v}]] = '1';
    }

    set<string> ans;
    ans.insert(t);

    using P = pair<string,vector<int>>;
    queue<P> qq;
    qq.push({t,par});

    while(!qq.empty()){
        P now = qq.front();
        qq.pop();

        string nt = now.fi;
        vector<int> np = now.se;

        rep(i,m){
            if(nt[i]=='1') continue;

            int u=e[i].fi, v=e[i].se;
            if(abs(d[u]-d[v])==1){
                if(d[v]<d[u]) swap(u,v);

                int parv = np[v];
                int id = e2id[{min(parv,v),max(parv,v)}];

                assert(nt[id]=='1');
                nt[id] = '0';
                nt[i] = '1';
                if(!ans.count(nt)){
                    np[v] = u;
                    ans.insert(nt);
                    qq.push({nt,np});
                    np[v] = parv;

                    if(ans.size()==k) break;
                }
                nt[id] = '1';
                nt[i] = '0';
            }
        }

        if(ans.size()==k) break;
    }

    cout << ans.size() << endl;
    for(string s:ans) cout << s << endl;
    return 0;
}
