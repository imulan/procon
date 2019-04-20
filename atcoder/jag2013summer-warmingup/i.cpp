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

using P = pair<int,int>;
using E = pair<P,P>;

const int dx[4]={1,-1,0,0};
const int dy[4]={0,0,1,-1};

int main(){
    int n;
    cin >>n;

    set<P> points;
    set<E> edges;

    int v = 0;
    map<P,int> p2id;

    UF uf(4*n);

    rep(pp,n){
        int x,y;
        cin >>x >>y;
        vector<P> z;
        for(P d:vector<P>({{0,0},{1,0},{1,1},{0,1}})){
            z.pb({x+d.fi, y+d.se});
        }

        // dbg(v);
        rep(i,4){
            points.insert(z[i]);
            if(!p2id.count(z[i])){
                p2id[z[i]] = v;
                ++v;
            }
        }
        rep(i,4){
            P p = z[i], q = z[(i+1)%4];
            edges.insert({min(p,q),max(p,q)});
            uf.unite(p2id[p], p2id[q]);
        }
    }

    set<int> cc_idx;
    rep(i,v) cc_idx.insert(uf.root(i));
    int cc = cc_idx.size();

    int e = edges.size();
    int f = n+1;
    // v-e+(f+g) = 2
    int g = 2-v+e-f;
    cout << g + cc-1 << "\n";
    return 0;
}
