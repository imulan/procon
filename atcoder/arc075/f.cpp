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

int di(int x)
{
    int r=0;
    while(x>0)
    {
        x/=10;
        ++r;
    }
    return r;
}

const int pp=19;

int main()
{
    ll pw[pp]={};
    pw[0]=1;
    for(int i=1; i<pp; ++i) pw[i]=pw[i-1]*10;

    int D;
    cin >>D;

    ll PW=1;
    if(D%10==0)
    {
        PW*=9;
        D/=10;
    }
    while(D%10==0)
    {
        PW*=10;
        D/=10;
    }

    // dbg(pw[(di(D)+1)/2]);

    int d=di(D);

    int ans=0;
    for(int i=1; i<pw[(d+1)/2]; ++i)
    {

    }

    cout << PW*ans << endl;
    return 0;
}
