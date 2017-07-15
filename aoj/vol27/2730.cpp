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

int solve(string s)
{
    int ret = 0;
    int S = s.size();

    vector<int> l(S+1),r(S+1);
    vector<int> rpos;
    rep(i,S)
    {
        if(s[i]=='>') rpos.pb(i);

        l[i+1] = l[i]+(s[i]=='<');
        r[i+1] = r[i]+(s[i]=='>');
    }

    rep(i,S)if(s[i]=='>')
    {
        int L=i, R=S+1;
        while(R-L>1)
        {
            int m = (L+R)/2;

            if(l[m] - l[i] <= r[i]) L=m;
            else R=m;
        }
        if(L<S) ret = max(ret,L+1);
        else
        {
            int idx = lower_bound(all(rpos),i)-rpos.begin();
            idx -= l[L]-l[i];
            ret = max(ret, S-rpos[idx]);
        }
    }

    return ret;
}

int main()
{
    int S;
    string s;
    cin >>S >>s;

    int ans = 0;
    ans = max(ans,solve(s));

    reverse(all(s));
    rep(i,S)
    {
        if(s[i]=='>') s[i]='<';
        else s[i]='>';
    }

    ans = max(ans,solve(s));
    cout << ans << endl;
    return 0;
}
