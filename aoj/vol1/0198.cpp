#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef vector<int> vi;

inline vi rotate(const vi &t)
{
    int idx=0;
    while(idx<6 && t[idx]!=0) ++idx;

    vi a;
    if(idx==0) a=vi({0,1,2,3,4,5});
    else if(idx==1) a=vi({1,5,2,3,0,4});
    else if(idx==2) a=vi({2,1,5,0,4,3});
    else if(idx==3) a=vi({3,1,0,5,4,2});
    else if(idx==4) a=vi({4,0,2,3,5,1});
    else if(idx==5) a=vi({5,4,2,3,1,0});

    vi ret(6);
    rep(i,6) ret[i]=t[a[i]];
    return ret;
}

inline vi normalize(const vi &t)
{
    vi side({t[1],t[2],t[4],t[3]});

    vector<vi> s;
    rep(i,4)
    {
        vi a(4);
        rep(j,4) a[j]=side[(j+i)%4];
        s.pb(a);
    }
    sort(all(s));
    return s[0];
}

int main()
{
    int n;
    while(cin >>n,n)
    {
        vector<vi> d(n);
        rep(i,n)
        {
            vi t(6);
            rep(j,6)
            {
                string s;
                cin >>s;
                if(s=="Red") t[j]=0;
                else if(s=="Yellow") t[j]=1;
                else if(s=="Blue") t[j]=2;
                else if(s=="Magenta") t[j]=3;
                else if(s=="Green") t[j]=4;
                else if(s=="Cyan") t[j]=5;
            }
            d[i]=rotate(t);
        }

        set<vi> s[6];
        rep(i,n) s[d[i][5]].insert(normalize(d[i]));

        int diff=0;
        rep(i,6) diff+=s[i].size();
        cout << n-diff << endl;
    }
    return 0;
}
