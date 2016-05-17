#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

typedef pair<int,string> P;

vector<string> split(const string &s, char d)
{
    vector<string> ret;
    stringstream ss(s);
    string buf;
    while(getline(ss,buf,d)) ret.pb(buf);
    return ret;
}

int main()
{
    int n;
    while(cin >>n,n)
    {
        cin.ignore();

        vector<string> s(n);
        rep(i,n)
        {
            getline(cin,s[i]);
        }

        map<string,int> m;
        rep(i,n)
        {
            vector<string> v=split(s[i],' ');
            rep(j,v.size())
            {
                if(m.find(v[j])==m.end()) m[v[j]]=1;
                else ++m[v[j]];
            }
        }

        vector<P> ans;

        char head;
        scanf(" %c", &head);
        for(const auto &x : m)
        {
            if(x.fi[0]==head) ans.pb(P(-x.se,x.fi));
        }

        sort(all(ans));

        if(ans.size()==0) printf("NA\n");
        else
        {
            rep(i,min(5,(int)ans.size()))
            {
                if(i) printf(" ");
                cout << ans[i].se;
            }
            cout << endl;
        }

    }
    return 0;
}
