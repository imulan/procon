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

int main()
{
    int n;
    scanf(" %d", &n);
    vector<int> a(n);
    rep(i,n) scanf(" %d", &a[i]);

    int suma = 0;
    rep(i,n) suma += a[i];

    int V = 1<<17;
    if(n<17) V = 1<<n;
    vector<vector<bool>> mark(V,vector<bool>(2));

    priority_queue<P,vector<P>,greater<P>> pq;
    rep(d,min(17,n))
    {
        for(int i=(1<<d); i<(1<<(d+1)); ++i)
        {
            rep(j,2) pq.push({d,pi(i,j)});
        }
    }

    set<ll> ans;
    for(int i=n-1; i>=0; --i)
    {
        while(a[i]>0)
        {
            bool valid = true;
            while(!pq.empty())
            {
                P p = pq.top(); pq.pop();
                pi e = p.se;
                if(mark[e.fi][e.se]) continue;

                int d = p.fi;
                if(d>i)
                {
                    valid = false;
                    pq.push(p);
                    break;
                }

                // 塗る
                mark[e.fi][e.se] = true;
                ll v = 2*e.fi+e.se;
                ++d;
                // その深さまで行く
                while(d<i+1)
                {
                    if(v<V) mark[v][0]=true;
                    v*=2;
                    ++d;
                }
                ans.insert(v);
                --a[i];
                break;
            }

            if(!valid) break;
        }

        // 余りを適当に処理する
        for(ll j=(1LL<<(i+1)); j<(1LL<<(i+2)); ++j)
        {
            if(a[i]==0) break;

            if(!ans.count(j))
            {
                ans.insert(j);
                --a[i];
            }
        }
    }

    for(const auto &x:ans) printf("%lld\n", x);
    return 0;
}
