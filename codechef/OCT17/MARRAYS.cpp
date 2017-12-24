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

using vi = vector<int>;
using vl = vector<ll>;
using P = pair<ll,int>;

const ll INF = LLONG_MAX/3;

ll solve()
{
    int n;
    scanf(" %d", &n);

    vi m(n);
    vector<vi> a(n);
    rep(i,n)
    {
        scanf(" %d", &m[i]);
        a[i] = vi(m[i]);
        rep(j,m[i]) scanf(" %d", &a[i][j]);
    }

    if(n==1) return 0;

    vector<vl> dp(m[0],vl(2));
    rep(i,m[0])
    {
        dp[i][0] = -a[0][i];
        dp[i][1] = a[0][i];
    }

    for(int i=1; i<n; ++i)
    {
        vector<vl> nx(m[i],vl(2,-INF));

        priority_queue<P,vector<P>,greater<P>> pq,prev;
        rep(j,m[i]) pq.push({a[i][(j+1)%m[i]],j});
        rep(j,m[i-1]) prev.push({a[i-1][j],j});

        multiset<ll> neg,pos;
        rep(j,m[i-1]) pos.insert(dp[j][1]);

        while(!pq.empty())
        {
            P now = pq.top();
            pq.pop();
            ll val = now.fi;
            int id = now.se;

            while(!prev.empty())
            {
                P pp = prev.top();
                ll vv = pp.fi;
                int ii = pp.se;

                if(vv<val)
                {
                    pos.erase(pos.find(dp[ii][1]));
                    neg.insert(dp[ii][0]);
                    prev.pop();
                }
                else break;
            }

            // printf("val %lld id %d\n", val,id);
            // dbg(vector<ll>(neg.begin(),neg.end()));
            // dbg(vector<ll>(pos.begin(),pos.end()));

            ll M = -INF;
            if(!neg.empty()) M = max(M, val*i+(*neg.rbegin()));
            if(!pos.empty()) M = max(M, -val*i+(*pos.rbegin()));

            nx[id][0] = max(nx[id][0], M-(ll)a[i][id]*(i+1));
            nx[id][1] = max(nx[id][1], M+(ll)a[i][id]*(i+1));
        }

        dp = nx;
    }

    ll ans = -INF;
    rep(i,m[n-1])
    {
        ans = max({ans, dp[i][0]+(ll)a[n-1][i]*n, dp[i][1]-(ll)a[n-1][i]*n});
    }
    return ans;
}

int main()
{
    int T;
    cin >>T;
    while(T--) cout << solve() << endl;
    return 0;
}
