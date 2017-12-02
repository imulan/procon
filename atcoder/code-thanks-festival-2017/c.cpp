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

using p = pair<ll,int>;

int main()
{
    int n,k;
    cin >>n >>k;
    vector<ll> a(n),b(n);
    rep(i,n) cin >>a[i] >>b[i];

    priority_queue<p,vector<p>,greater<p>> pq;
    rep(i,n) pq.push({a[i],i});

    ll ans = 0;
    while(k--)
    {
        p now = pq.top();
        pq.pop();

        ll v = now.fi;
        int ID = now.se;
        ans += v;
        
        pq.push({v+b[ID],ID});

    }
    cout << ans << endl;
    return 0;
}
