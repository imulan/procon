#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pi;
typedef pair<pi,string> P;
int score(int l,int ac)
{
    return 50*l + (int)(floor(0.000001+50*l/(0.8+0.2*ac)));
}

int main()
{
    int n;
    scanf(" %d", &n);
    vector<int> L(n);
    rep(i,n) scanf( "%d", &L[i]);

    vector<int> ac(n,0);
    map<string,vector<int>> mp;
    map<string,int> last;

    int T;
    scanf(" %d", &T);
    rep(i,T)
    {
        string name;
        char p;
        cin >>name >>p;

        int num=p-'A';
        ++ac[num];

        if(mp.find(name)==mp.end()) mp[name]=vector<int>(n,0);
        last[name]=i;

        mp[name][num]=score(L[num],ac[num]);
    }

    vector<P> v;
    for(const auto &m:mp)
    {
        string name=m.fi;
        vector<int> t=m.se;

        int sum=0;
        rep(i,n) sum+=t[i];

        v.pb(P(pi(-sum,last[name]),name));
    }
    sort(all(v));

    rep(i,v.size())
    {
        string name=v[i].se;

        printf("%d ", i+1);
        cout << name << " ";

        vector<int> t=mp[name];
        int sum=0;
        rep(j,n)
        {
            printf("%d ", t[j]);
            sum+=t[j];
        }
        printf("%d\n", sum);
    }
    return 0;
}
