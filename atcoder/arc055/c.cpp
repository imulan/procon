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

int main()
{
    string s;
    cin >>s;

    if(s.size()>2000) return 0;

    ll ans=0;
    for(int i=s.size()/2+1; i<s.size()-1; ++i)
    {
        string x=s.substr(0,i), y=s.substr(i);
        //cout <<"x="<<x<<" , y="<<y<<endl;

        for(int j=1; j<y.size(); ++j)
        {
            string a=y.substr(0,j), c=y.substr(j);
            //cout <<" a="<<a<<" , c="<<c<<endl;

            string ta=x.substr(0,a.size());
            string tc=x.substr(x.size()-c.size());
            //cout <<" ta="<<ta<<" , tc="<<tc<<endl;

            if(a==ta && c==tc)
            {
                ++ans;
                //cout <<" a="<<a<<" , c="<<c<<endl;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
