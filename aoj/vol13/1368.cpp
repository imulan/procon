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

int x[10][10];

int calc(string s)
{
    int r = 0;
    rep(i,s.size()) r = x[r][s[i]-'0'];
    return r;
}

int main()
{
    rep(i,10)rep(j,10) cin >> x[i][j];

    int ans = 0;
    rep(i,10000)
    {
        string t = to_string(i);
        reverse(all(t));
        while(t.size()<4) t+='0';
        reverse(all(t));

        int e = calc(t);
        t += '0'+e;

        int a = 0;
        rep(j,5)
        {
            char c = t[j];
            rep(k,10)if(k!=c-'0')
            {
                t[j]=k+'0';
                if(calc(t)==0) a=1;
            }
            t[j]=c;
        }
        rep(j,4)if(t[j]!=t[j+1])
        {
            swap(t[j],t[j+1]);
            if(calc(t)==0) a=1;
            swap(t[j],t[j+1]);
        }

        ans += a;
    }
    cout << ans << endl;
    return 0;
}
