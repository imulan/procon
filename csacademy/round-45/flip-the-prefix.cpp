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

int main()
{
    int n;
    cin >>n;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    int s = 0;
    int f = 0;
    vector<int> ans;
    for(int i=n-1; i>=0; --i)
    {
        s += abs(a[i]);
        if(a[i]>0 && f)
        {
            f = !f;
            ans.pb(i+1);
        }
        if(a[i]<0 && !f)
        {
            f = !f;
            ans.pb(i+1);            
        }
    }

    printf("%d\n", s);
    int A = ans.size();
    rep(i,A) printf("%d%c", ans[i], (i==A-1?'\n':' '));
    return 0;
}
