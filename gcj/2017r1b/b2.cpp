#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const string NG = "IMPOSSIBLE";

using P = pair<int,char>;

bool check(string s)
{
    int S=s.size();
    rep(i,S)
    {
        string ok;
        if(s[i]=='O') ok="B";
        else if(s[i]=='G') ok="R";
        else if(s[i]=='V') ok="Y";
        else if(s[i]=='R') ok="YBG";
        else if(s[i]=='Y') ok="RBV";
        else if(s[i]=='B') ok="RYO";

        int c=0;
        rep(j,ok.size())if(ok[j] == s[(i-1+S)%S]) c+=1;
        rep(j,ok.size())if(ok[j] == s[(i+1)%S]) c+=2;

        if(c<3) return false;
    }
    return true;
}

string small(int R, int Y, int B)
{
    int n=R+Y+B;
    int m = max({R,Y,B});
    if(2*m>n) return NG;

    vector<P> p;
    p.pb(P(R,'R'));
    p.pb(P(Y,'Y'));
    p.pb(P(B,'B'));
    sort(all(p));

    string s(n,' ');
    rep(i,p[2].fi) s[2*i] = p[2].se;

    int st=n-1;
    if(n%2==1) --st;
    rep(i,p[1].fi) s[st-2*i] = p[1].se;

    rep(i,n)if(s[i]==' ') s[i]=p[0].se;

    return s;
}

string solve()
{
    string col="ROYGBV";

    int n,num[6];
    cin >>n;
    rep(i,6) cin >>num[i];

    int kind=0;
    rep(i,6) kind+=(num[i]>0);

    if(kind==1) return NG;
    if(kind==2)
    {
        vector<int> idx;
        rep(i,6)if(num[i]>0) idx.pb(i);

        if(num[idx[0]] != num[idx[1]]) return NG;

        string s="";
        rep(i,num[idx[0]])
        {
            s += col[idx[0]];
            s += col[idx[1]];
        }
        if(!check(s)) return NG;

        return s;
    }

    for(int i=1; i<6; i+=2)
    {
        if(num[i]>0)
        {
            if(num[i] >= num[(i+3)%6]) return NG;
        }
        num[(i+3)%6] -= num[i];
    }

    string s = small(num[0],num[2],num[4]);
    if(s == NG) return s;

    for(int i=1; i<6; i+=2)
    {
        if(num[i]>0)
        {
            string a(1,col[(i+3)%6]);
            rep(j,num[i])
            {
                a += col[i];
                a += col[(i+3)%6];
            }

            int idx = s.find(string(1,col[(i+3)%6]));
            s.replace(idx,1,a);
        }
    }

    return s;
}

int main()
{
    int T;
    cin >>T;
    rep(t,T)
    {
        printf("Case #%d: ", t+1);
        cout << solve() << endl;
    }
    return 0;
}
