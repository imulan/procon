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

const int N=100000;
ll s[100000]={};

int main()
{
    int a;
    cin >>a;

    for(int i=1; i<N; ++i) s[i] = s[i-1]+i;

    int idx = 0;
    while(idx<N && s[idx]<a) ++idx;

    a = s[idx]-a;

    cout << string(idx-a,')')+"("+string(a,')')+string(idx-1,'(') << endl;
    return 0;
}
