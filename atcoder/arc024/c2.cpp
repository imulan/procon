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

typedef vector<int> vi;
typedef pair<vi,int> P;

int ct[100001][26]={0};

int main()
{
    int n,k;
    string s;
    cin >>n >>k >>s;

    int S=s.size();

    rep(i,S)
    {
        rep(j,26) ct[i+1][j]=ct[i][j];
        ++ct[i+1][s[i]-'a'];
    }

    vector<P> candidate;
    for(int i=k; i<=S; ++i)
    {
        vector<int> t(26);
        rep(j,26) t[j]=ct[i][j]-ct[i-k][j];
        candidate.pb( P(t,i-k) );
    }
    sort(all(candidate));

    string ans="NO";
    if(k<n)
    {
        int C=candidate.size();
        int st=0;
        for(int i=1; i<C; ++i)
        {
            if(candidate[st].fi == candidate[i].fi)
            {
                if(abs(candidate[st].se - candidate[i].se)>=k)
                {
                    ans="YES";
                    break;
                }
            }
            else st=i;
        }
    }
    cout << ans << endl;
    return 0;
}
