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

struct Fraction
{
    // numerator / denominator
    ll num,den;

    bool operator<(const Fraction &r) const {
        return num*r.den < den*r.num;
    }
};

vector<Fraction> construct(int m, int lim)
{
    vector<Fraction> ret;
    for(int i=2; i<=m; ++i)
    {
        for(int j=1; j<i; ++j)
        {
            if(Fraction{lim,m}<Fraction{j,i}) break;
            if(__gcd(i,j)==1) ret.pb({j,i});
        }
    }

    sort(all(ret));
    return ret;
}

int main()
{
    int m,k;
    cin >>m >>k;

    int l=0, r=min(800000/m,m-1);
    vector<Fraction> f;
    while(r-l>1)
    {
        int mid = (l+r)/2;
        f = construct(m,mid);

        if(f.size()>=k) r=mid;
        else l=mid;
    }

    f = construct(m,r);

    if(f.size()<k) printf("-1\n");
    else printf("%lld %lld\n", f[k-1].num, f[k-1].den);
    return 0;
}
