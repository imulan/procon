#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

struct UnionFind{
    int n;
    vector<int> d;
    vector<ll> w;
    UnionFind(){}
    UnionFind(int N):n(N),d(N,-1),w(N,0){}
    int root(int v){
        if(d[v]<0) return v;
        return root(d[v]);
    }
    ll calc(int v){
        if(d[v]<0)return 0;
        return calc(d[v])+w[v];
    }
    bool unite(int X, int Y, int W){
        ll A=calc(X);
        ll C=calc(Y);
        X = root(X); Y = root(Y);
        if(X==Y) return false;
        if(size(X) < size(Y)){
            swap(X,Y);
            W=-W;
            swap(A,C);
        }
        ll B=W+A-C;
        w[Y]=B;
        d[X] += d[Y];
        d[Y] = X;
        return true;
    }
    int size(int v){ return -d[root(v)]; }
    bool same(int X, int Y){ return root(X)==root(Y); }
};

int n,q;
ll sum[100010];

int main(){
    cin>>n>>q;
    UnionFind uf(n);
    rep(i,q){
        string s;
        cin>>s;
        if(s=="COMPARE"){
            int a,b;
            cin>>a>>b;
            a--;b--;
            if(uf.root(a)!=uf.root(b)){
                cout<<"WARNING"<<endl;
                continue;
            }
            ll va=uf.calc(a)+sum[a];
            ll vb=uf.calc(b)+sum[b];
            cout<<vb-va<<endl;
        }else if(s=="IN"){
            int a,b,c;
            cin>>a>>b>>c;
            a--;b--;
            uf.unite(a,b,c-(sum[b]-sum[a]));
            sum[a]+=c;
            sum[b]+=c;
        }
    }
    return 0;
}
