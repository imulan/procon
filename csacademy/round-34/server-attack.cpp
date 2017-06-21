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

    int t[5005]={};
    rep(i,n)
    {
        int a,b;
        cin >>a >>b;
        if(a==1) t[b]=1;
        else t[b]=-1919;
    }

    rep(i,5004)
    {
        if(t[i+1]==1) continue;
        t[i+1]+=t[i];
    }

    int ans = 0;
    rep(i,5005) ans += (t[i]==1);
    cout << ans << endl;
    return 0;
}
