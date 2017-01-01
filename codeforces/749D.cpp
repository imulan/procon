#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int INF=1010101010;

typedef pair<ll,int> pl;

struct MaxSegTree{
    long n; vector<pl> dat;
    //初期化
    MaxSegTree(long _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<pl>(2*n-1,pl(-1,-1));
    }
    //k番目(0-indexed)の値をaに変更
    void update(long k, pl a){
        k+=n-1;
        dat[k]=a;
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k]=max(dat[2*k+1],dat[2*k+2]);
        }
    }
    //内部的に投げられるクエリ
    pl _query(long a, long b, long k, long l, long r){
        if(r<=a || b<=l) return pl(-1,-1);

        if(a<=l && r<=b) return dat[k];

        pl vl=_query(a,b,2*k+1,l,(l+r)/2);
        pl vr=_query(a,b,2*k+2,(l+r)/2,r);
        return max(vl,vr);
    }
    //[a,b)の最大値を求める
    pl query(long a, long b){
        return _query(a,b,0,0,n);
    }
};

vector<int> B[200000];

int main()
{
    int n;
    scanf(" %d", &n);

    MaxSegTree st(n);
    rep(i,n) st.update(i,pl(0,i));

    set<int> s;
    vector<int> min_bid(n,INF);
    rep(i,n)
    {
        int a,b;
        scanf(" %d %d", &a, &b);
        --a;

        min_bid[a] = min(min_bid[a],b);
        s.insert(a);
        st.update(a,pl(b,a));
        B[a].pb(b);
    }

    int Q;
    scanf(" %d", &Q);
    while(Q--)
    {
        int k;
        scanf(" %d", &k);

        vector<int> l(k),p;
        vector<pl> res(k);
        rep(i,k)
        {
            scanf(" %d", &l[i]);
            --l[i];

            if(s.find(l[i])!=s.end())
            {
                p.pb(l[i]);
                s.erase(l[i]);
            }

            res[i] = st.query(l[i],l[i]+1);
            st.update(l[i],pl(0,l[i]));
        }

        if(s.size()==0) printf("0 0\n");
        else if(s.size()==1)
        {
            int win = *s.begin();
            printf("%d %d\n", win+1, min_bid[win]);
        }
        else
        {
            pl win = st.query(0,n);
            int idx = win.se;

            pl other = max(st.query(0,idx),st.query(idx+1,n));
            int price = other.fi;

            printf("%d %d\n", idx+1, *lower_bound(all(B[idx]), price));
        }

        rep(i,k) st.update(l[i],res[i]);
        rep(i,p.size()) s.insert(p[i]);
    }

    return 0;
}
