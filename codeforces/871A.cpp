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

vector<int> c({4,6,8,9,10,14,15,16,18,20});

int query(int n)
{
    int ret = 0;
    if(n%2==1)
    {
        if(n<9) return -1;
        n-=9;
        ++ret;
    }

    if(n%4==2)
    {
        if(n<6) return -1;
        n-=6;
        ++ret;
    }

    ret += n/4;
    return ret;
}

int main()
{
    int Q;
    scanf(" %d", &Q);
    while(Q--)
    {
        int n;
        scanf(" %d", &n);
        printf("%d\n", query(n));
    }
    return 0;
}
