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

struct UF{
    int n;
    //正だったらその頂点の親,負だったら根で連結成分の個数
    vector<int> d;
    UF() {}
    UF(int N):n(N), d(N,-1){}
    int root(int v){
        if(d[v]<0) return v;
        return d[v]=root(d[v]);
    }
    bool unite(int X,int Y){
        X=root(X); Y=root(Y);
        if(X==Y) return false;
        if(size(X) < size(Y)) swap(X,Y);
        d[X]+=d[Y];
        d[Y]=X;
        return true;
    }
    int size(int v){ return -d[root(v)]; }
    bool same(int X,int Y){ return root(X)==root(Y); }
};

using pi = pair<int,int>;

const int N = 100000;
const int INF = 19191919;

struct edge{ int to,cost; };
vector<edge> G[N];

vector<int> query[N];

int main(){
    int n,m,k,q;
    cin >>n >>m >>k >>q;

    vector<int> a(m),b(m),c(m);
    rep(i,m){
        cin >>a[i] >>b[i] >>c[i];
        --a[i]; --b[i];
        G[a[i]].pb({b[i],c[i]});
        G[b[i]].pb({a[i],c[i]});
    }

    vector<int> d(n,INF);
    priority_queue<pi,vector<pi>,greater<pi>> pq;
    while(k--){
        int f;
        cin >>f;
        --f;
        d[f] = 0;
        pq.push({0,f});
    }

    vector<int> s(q),t(q);
    rep(i,q){
        cin >>s[i] >>t[i];
        --s[i]; --t[i];
    }

    while(!pq.empty()){
        pi now = pq.top();
        pq.pop();
        int v = now.se;
        if(now.fi>d[v]) continue;
        for(const auto &e:G[v]){
            if(d[e.to]>d[v]+e.cost){
                d[e.to]=d[v]+e.cost;
                pq.push({d[e.to],e.to});
            }
        }
    }

    vector<pi> e;
    rep(i,m) e.pb({min(d[a[i]],d[b[i]]), i});
    sort(all(e));
    reverse(all(e));

    sort(all(d),greater<int>());
    vector<int> l(q,-1), r(q,n-1);
    rep(loop,18){
        rep(i,N) query[i].clear();
        rep(i,q) query[(l[i]+r[i])/2].pb(i);

        UF uf(n);
        int idx = 0;
        rep(i,n){
            while(idx<m && e[idx].fi>=d[i]){
                int id = e[idx].se;
                uf.unite(a[id],b[id]);
                ++idx;
            }

            for(int qid:query[i]){
                if(uf.same(s[qid],t[qid])) r[qid] = i;
                else l[qid] = i;
            }
        }
    }

    rep(i,q) cout << d[r[i]] << endl;
    return 0;
}
