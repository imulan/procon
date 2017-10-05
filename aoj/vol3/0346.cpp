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

string solve()
{
    set<int> s;
    map<int,int> ct;
    rep(i,12)
    {
        int e;
        cin >>e;
        s.insert(e);
        ++ct[e];
    }

    for(int i:s)for(int j:s)for(int k:s)
    {
        map<int,int> t(ct);

        if(t[i]>=4) t[i]-=4;
        else continue;
        if(t[j]>=4) t[j]-=4;
        else continue;
        if(t[k]>=4) t[k]-=4;
        else continue;

        return "yes";
    }

    return "no";
}


int main()
{
    cout << solve() << endl;
    return 0;
}
