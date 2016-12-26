#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

const int N=100;
bool prime[N];
vector<int> p;

int main()
{
    fill(prime,prime+N,true);
    prime[0]=prime[1]=false;
    for(int i=2; i<N; ++i)
    {
        if(prime[i]) for(int j=i*2; j<N; j+=i) prime[j]=false;
    }
    rep(i,N)if(prime[i]) p.pb(i);

    int ct=0;

    int now=0;
    int q=p[0];
    rep(i,20)
    {
        cout << q << endl;
        fflush(stdout);

        string s;
        cin >>s;

        if(s=="yes")
        {
            ++ct;
            if(q*q<=100) q = q*q;
            else
            {
                ++now;
                q = p[now];
            }
        }
        else
        {
            ++now;
            q = p[now];
        }

        if(ct>1) break;
    }

    string ans="prime";
    if(ct>1) ans="composite";

    cout << ans << endl;
    fflush(stdout);
    return 0;
}
