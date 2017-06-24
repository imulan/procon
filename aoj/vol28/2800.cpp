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

int solve()
{
    int n;
    cin >>n;
    int ct[3]={};
    rep(i,n)
    {
        int a;
        cin >>a;
        ++ct[a%3];
    }

    int x=ct[1], y=ct[2];
    if(x>y) swap(x,y);

    if(y==0) return 1;

    int ret = 1+ct[0];
    --y;

    int k = min(x,y);
    ret += 2*k;

    x-=k;
    y-=k;

    if(y>=2) ret+=2;
    else ret+=(x>0 || y>0);

    return ret;
}

int main()
{
    cout << solve() << endl;
    return 0;
}
