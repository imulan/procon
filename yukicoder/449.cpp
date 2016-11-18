#include <bits/stdc++.h>
using namespace std;

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

struct SumSegTree{
    long n; vector<ll> dat;
    //初期化
    SumSegTree(long _n){
        n=1;
        while(n<_n) n*=2;
        dat=vector<ll>(2*n-1,0);
    }
    //k番目(0-indexed)の値を+a
    void add(long k, ll a){
        k+=n-1;
        dat[k]+=a;
        //更新
        while(k>0){
            k=(k-1)/2;
            dat[k]=dat[2*k+1]+dat[2*k+2];
        }
    }
    //内部的に投げられるクエリ
    ll _query(long a, long b, long k, long l, long r){
        if(r<=a || b<=l) return LLONG_MIN;

        if(a<=l && r<=b) return dat[k];
        else{
            ll vl=_query(a,b,2*k+1,l,(l+r)/2);
            ll vr=_query(a,b,2*k+2,(l+r)/2,r);
            return vl+vr;
        }
    }
    //[a,b)の最大値を求める
    ll query(long a, long b){
        return _query(a,b,0,0,n);
    }
};

inline int score(int l,int ac)
{
    return 50*l + (int)(floor(0.000001+50*l/(0.8+0.2*ac)));
}

const int N=16000;
tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>  s[N];
SumSegTree st(N);

int main()
{
    cin.tie(0);ios::sync_with_stdio(false);

    int n;
    cin >>n;
    vector<int> L(n);
    rep(i,n) cin >>L[i];

    vector<int> ac(n,0),sum,last;
    int participant=0;
    unordered_map<string,int> name_to_id;

    int T;
    cin >>T;
    rep(i,T)
    {
        string name;
        char p;
        cin >>name >>p;
        if(p=='?')
        {
            int id = name_to_id[name];

            int up = st.query(sum[id]+1,N);
            int same = s[sum[id]].order_of_key(last[id]);
            printf("%d\n", up+same+1);
        }
        else
        {
            if(name_to_id.find(name)==name_to_id.end())
            {
                name_to_id[name] = participant++;
                sum.pb(0);
                last.pb(0);
            }

            int id = name_to_id[name];
            int problem = p-'A';

            ++ac[problem];

            if(sum[id]!=0)
            {
                s[sum[id]].erase(last[id]);
                st.add(sum[id],-1);
            }
            sum[id] += score(L[problem],ac[problem]);
            last[id]=i;
            s[sum[id]].insert(i);
            st.add(sum[id],1);
        }
    }
    return 0;
}
