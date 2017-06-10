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

int main()
{
    int ct[9]={};

    int n,a;
    cin >>n;
    rep(i,n)
    {
        cin >>a;
        a = min(8,a/400);
        ++ct[a];
    }

    int x=0;
    rep(i,8) x+=(ct[i]>0);

    if(x==0)
    {
        x = 1;
        if(ct[8]>0) --ct[8];
    }

    printf("%d %d\n", x,x+ct[8]);
    return 0;
}
