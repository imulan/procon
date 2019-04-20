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

void solve()
{
    int n,m;
    cin >>n >>m;

    vector<int> minSalary(n),offeredSalary(m),maxJobOffers(m);
    rep(i,n) cin >>minSalary[i];
    rep(i,m) cin >>offeredSalary[i] >>maxJobOffers[i];

    vector<string> qual(n);
    rep(i,n) cin >>qual[i];

    int jobGetStudent = 0, notHireCompany = 0;
    ll Total = 0;

    vector<int> h(m);
    rep(i,n)
    {
        int x = -1;
        int max = minSalary[i];
        rep(j,m)if(qual[i][j]=='1')
        {
            if(maxJobOffers[j]-h[j]>0 && max<=offeredSalary[j])
            {
                x = j;
                max = offeredSalary[j];
            }
        }

        if(x!=-1)
        {
            ++h[x];
            Total += offeredSalary[x];
            ++jobGetStudent;
        }
    }

    rep(i,m) notHireCompany += (h[i]==0);

    printf("%d %lld %d\n", jobGetStudent, Total, notHireCompany);
}

int main()
{
    int T;
    cin >>T;
    while(T--) solve();
    return 0;
}
