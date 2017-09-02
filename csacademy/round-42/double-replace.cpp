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
    string s,a,b;
    cin >>s >>a >>b;

    int S = s.size(), A = a.size(), B = b.size();
    int idx = 0;
    while(idx<=S-A)
    {
        string t = s.substr(idx,A);
        if(t==a || t==b)
        {
            if(t==a) rep(i,A) s[idx+i] = b[i];
            else rep(i,B) s[idx+i] = a[i];
            idx+=A;
        }
        else ++idx;
    }
    cout << s << endl;
    return 0;
}
