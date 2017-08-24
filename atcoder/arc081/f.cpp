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

// largest rectangle in histogram
int calc(const vector<int> &h)
{
    int n = h.size();
    vector<int> L(n),R(n),st(n);

    int t=0;
    rep(i,n)
    {
        while(t>0 && h[st[t-1]]>=h[i]) --t;
        L[i] = (t==0?0:st[t-1]+1);
        st[t++] = i;
    }

    t = 0;
    for(int i=n-1; i>=0; --i)
    {
        while(t>0 && h[st[t-1]]>=h[i]) --t;
        R[i] = (t==0?n:st[t-1]);
        st[t++] = i;
    }

    int ret = 0;
    rep(i,n) ret = max(ret, (h[i]+1)*(R[i]-L[i]+1));
    return ret;
}

int main()
{
    int h,w;
    cin >>h >>w;
    vector<string> s(h);
    rep(i,h) cin >>s[i];

    vector<vector<int>> f(h-1,vector<int>(w-1,-1));
    rep(i,h-1)rep(j,w-1)
    {
        int ct = 0;
        rep(ii,2)rep(jj,2) ct += (s[i+ii][j+jj]=='#');
        if(ct%2==1) f[i][j] = 0;
    }

    rep(j,w-1)if(f[0][j]!=0) f[0][j]=1;
    for(int i=1; i<h-1; ++i)rep(j,w-1)if(f[i][j]!=0)f[i][j] = f[i-1][j]+1;

    int ans = max(h,w);
    rep(i,h-1) ans = max(ans,calc(f[i]));
    cout << ans << endl;
    return 0;
}
