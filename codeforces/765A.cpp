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
    int n;
    string h;
    cin >>n >>h;

    int ct = 0;
    map<string,int> name2id;
    name2id[h] = ct++;

    vector<int> from(n), to(n);
    rep(i,n)
    {
        string s;
        cin >>s;

        string x = s.substr(0,3), y = s.substr(5);
        if(!name2id.count(x)) name2id[x] = ct++;
        if(!name2id.count(y)) name2id[y] = ct++;

        from[i] = name2id[x];
        to[i] = name2id[y];
    }

    vector<int> in(ct), out(ct);
    rep(i,n)
    {
        ++out[from[i]];
        ++in[to[i]];
    }

    string ans = "home";
    for(int i=1; i<ct; ++i)if(in[i]!=out[i]) ans = "contest";

    cout << ans << endl;
    return 0;
}
