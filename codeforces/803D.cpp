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

const int INF = 19191919;

vector<int> idx;
bool valid(const string &s, int x, int k)
{
    // printf(" CHECK %d\n", x);
    int n = s.size();

    int st = 0;
    int ct = 0;
    while(st+x<n)
    {
        auto itr = upper_bound(all(idx),st+x-1);
        --itr;

        int nx = *itr;
        // printf(" st %d nx %d\n", st,nx);

        if(st>=nx) return false;

        st = nx+1;
        ++ct;
    }

    return ct+1<=k;
}

int main()
{
    int k;
    cin >>k;
    cin.ignore();
    string s;
    getline(cin,s);

    int S = s.size();
    rep(i,S)if(s[i]==' ') s[i]='-';

    idx.pb(-1);
    rep(i,S)if(s[i]=='-') idx.pb(i);
    idx.pb(INF);

    // dbg(idx);
    int l=0, r=S;
    while(r-l>1)
    {
        int m = (l+r)/2;
        if(valid(s,m,k)) r=m;
        else l=m;
    }
    cout << r << endl;
    return 0;
}
