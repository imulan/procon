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

using pl = pair<ll,ll>;

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

ll read()
{
    string s;
    cin >>s;

    int m = 1;
    if(s[0]=='-')
    {
        m = -1;
        s = s.substr(1);
    }

    int S = s.size();
    ll ret = atoll(s.substr(0,S-4).c_str())*1000 + atoll(s.substr(S-3).c_str());

    return m*ret;
}

int main()
{
    int n;
    scanf(" %d", &n);

    ll R = read();

    vector<pl> p(n);
    rep(i,n)
    {
        ll x=read(), y=read();
        p[i] = {x,y};
    }
    sort(all(p));

    UF uf(n);
    int idx = 0;
    set<pl> now;
    rep(i,n)
    {
        while(idx<n && p[idx].fi<=p[i].fi+R)
        {
            now.insert({p[idx].se,idx});
            ++idx;
        }

        auto itr = now.lower_bound({p[i].se-R,-1});
        while(itr!=now.end() && itr->fi<=p[i].se+R)
        {
            int id = itr->se;
            uf.unite(i,id);
            itr = now.erase(itr);
        }
    }

    set<int> s;
    rep(i,n) s.insert(uf.root(i));
    cout << s.size() << endl;
    return 0;
}
