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

int b[7][7]={
    {7,8,18,0,1,2,3},
    {8,9,0,1,10,3,4},
    {18,0,17,2,3,16,5},
    {0,1,2,3,4,5,6},
    {1,10,3,4,11,6,12},
    {2,3,16,5,6,15,14},
    {3,4,5,6,12,14,13}
};

string solve(string s)
{
    set<int> cell;
    rep(i,1<<19)
    {
        int c = 0;
        rep(j,7)
        {
            int v = 0;
            rep(k,7) v |= (i>>b[j][k]&1)<<k;

            c |= (s[v]-'0')<<j;
        }
        cell.insert(c);
    }

    for(const auto &x:cell)
    {
        // dbg(x);
        if((x>>3&1) != (s[x]-'0')) return "no";
    }
    return "yes";
}

int main()
{
    string s;
    while(cin >>s,(s!="#")) cout << solve(s) << '\n';
    return 0;
}
