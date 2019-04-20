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

vector<int> cv(const string &s)
{
    int n = s.size()
    vector<int> v(n);
    rep(i,n) v[i] = s[i]-'0';
    return v;
}

bool all_zero(const vector<int> &v)
{
    rep(i,v.size())if(v[i]!=0) return false;
    return true;
}

ll solve()
{
    string s;

    cin >>s;
    vector<int> a = cv(s);
    cin >>s;
    vector<int> b = cv(s);

    if(all_zero(b))
    {
        if(all_zero(a)) return 0;
        else return -1;
    }

    int n = a.size();
    ll ret = LLONG_MAX;
    
    // a[i]とb[0]の位置を合わせる
    rep(i,n)
    {
        ll t = i;
        vector<bool> flip(n);
        rep(j,n)
        {
            if(a[(j+i)%n] != b[j]) flip[(j+i)%n] = true;
        }




    }

    return ret;
}

int main()
{
    cout << solve() << endl;
    return 0;
}
