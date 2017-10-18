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
using P = pair<int,pi>;

struct MinSegTree{
    int n; vector<int> dat;
    //初期化
    MinSegTree(int _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<int>(2*n-1,19191919);
    }
    //k番目(0-indexed)の値をaに変更
    void update(int k, int a){
        k+=n-1;
        dat[k]=a;
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k]=min(dat[2*k+1],dat[2*k+2]);
        }
    }
    //内部的に投げられるクエリ
    int _query(int a, int b, int k, int l, int r){
        if(r<=a || b<=l) return 19191919;

        if(a<=l && r<=b) return dat[k];

        int vl=_query(a,b,2*k+1,l,(l+r)/2);
        int vr=_query(a,b,2*k+2,(l+r)/2,r);
        return min(vl,vr);
    }
    //[a,b)
    int query(int a, int b){
        return _query(a,b,0,0,n);
    }
};

const int N=200001;
vector<int> Q[N];

int main()
{
    int n;
    cin >>n;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    MinSegTree st(n);
    rep(i,n) st.update(i,a[i]);

    rep(i,n) Q[a[i]].pb(i);

    priority_queue<P,vector<P>,greater<P>> pq;
    pq.push({st.query(0,n),{0,n}});

    ll ans = 0;
    while(!pq.empty())
    {
        ++ans;
        P now = pq.top();
        pq.pop();

        int val = now.fi;
        int l = now.se.fi, r = now.se.se;

        int idx = lower_bound(all(Q[val]),l) - Q[val].begin();
        for(int i=idx; i<Q[val].size(); ++i)
        {
            int j = Q[val][i];
            if(j>=r) break;

            if(l!=Q[val][i]) pq.push({st.query(l,Q[val][i]) ,{l,Q[val][i]}});
            l = Q[val][i]+1;
        }
        if(l!=r) pq.push({st.query(l,r),{l,r}});
    }
    cout << ans << endl;
    return 0;
}
