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

const string ok = "Yes", ng = "No";

string solve(int h, int w, int k)
{
    rep(i,h+1)rep(j,w+1)
    {
        int a = (h-i)*j + i*(w-j);
        if(a==k) return ok;
    }

    return ng;
}

int main()
{
    int n,m,k;
    cin >>n >>m >>k;
    cout << solve(n,m,k) << endl;
    return 0;
}
