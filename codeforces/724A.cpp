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

int d[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string n[7]={"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

string solve()
{
    map<string,int> m;
    rep(i,7) m[n[i]] = i;

    int x[2];
    rep(i,2)
    {
        string s;
        cin >>s;
        x[i] = m[s];
    }

    rep(i,11)if((x[0]+d[i])%7 == x[1]) return "YES";
    return "NO";
}

int main()
{
    cout << solve() << endl;
    return 0;
}
