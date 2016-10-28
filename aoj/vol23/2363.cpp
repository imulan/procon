#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

double calcE()
{
    int n,m;
    scanf(" %d %d", &n, &m);
    vector<int> v(m);
    vector<double> r(m);
    rep(i,m) scanf(" %d %lf", &v[i], &r[i]);

    double sum=0;
    rep(i,m) sum+=r[i];
    double rest=1.0-sum;

    rep(i,m) r[i]+=rest*r[i]/sum;

    double ret=0;
    rep(i,m) ret+=v[i]*r[i];
    return ret;
}

int main()
{
    int t;
    scanf(" %d", &t);

    double maxE=0;
    rep(i,t) maxE=max(maxE,calcE());
    double leader=calcE();

    string ans="NO";
    if(maxE-leader>0.0000001) ans="YES";
    cout << ans << endl;
    return 0;
}
