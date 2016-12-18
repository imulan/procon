#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

ll p10[18];

ll NotFizzBuzz(ll n)
{
    return n - n/3 - n/5 + n/15;
}

ll FizzBuzzLength(ll n)
{
    ll fizz=n/3, buzz=n/5;
    ll ret = fizz*4 + buzz*4;

    int digit=1;
    while(n>p10[digit])
    {
        ret += digit*(NotFizzBuzz(p10[digit]-1) - NotFizzBuzz(p10[digit-1]-1));
        ++digit;
    }
    ret += digit*(NotFizzBuzz(n) - NotFizzBuzz(p10[digit-1]-1));

    return ret;
}

int main()
{
    p10[0]=1;
    for(int i=1; i<18; ++i) p10[i]=p10[i-1]*10;

    ll s;
    cin >>s;

    ll l=0, r=100000000000000000LL;
    while(r-l>1)
    {
        ll m = (l+r)/2;
        if(FizzBuzzLength(m)<s) l=m;
        else r=m;
    }

    ll st_idx = s - FizzBuzzLength(l) - 1;

    string FB="";
    for(ll i=l+1; i<=l+20; ++i)
    {
        if(i%15==0) FB+="FizzBuzz";
        else if(i%3==0) FB+="Fizz";
        else if(i%5==0) FB+="Buzz";
        else FB+=to_string(i);
    }

    cout << FB.substr(st_idx,20) << '\n';
    return 0;
}
