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

int a,b;

bool fit(int X, int Y)
{
    if(X>Y) swap(X,Y);
    return X<=a && Y<=b;
}

int main()
{
    int n;
    cin >>n >>a >>b;
    if(a>b) swap(a,b);
    vector<int> x(n),y(n);
    rep(i,n) cin >>x[i] >>y[i];

    int ans = 0;
    rep(i,n)rep(j,i)
    {
        int area = x[i]*y[i] + x[j]*y[j];
        if(fit(x[i]+x[j],max(y[i],y[j])) || fit(x[i]+y[j],max(y[i],x[j])) || fit(max(x[i],x[j]),y[i]+y[j]) || fit(max(x[i],y[j]),y[i]+x[j])) ans = max(ans,area);
    }

    cout << ans << endl;
    return 0;
}
