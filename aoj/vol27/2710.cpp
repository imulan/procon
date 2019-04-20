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

int S;
string s;

const int N = 200;
int op[N],l[N],r[N],n[N];
int ct = 0;

int read(char c, int &idx)
{
    int ret = 0;
    if(c=='o')
    {
        if(s[idx]=='+') ret = 1;
        else if(s[idx]=='-') ret = -1;
        ++idx;
    }
    else if(c=='(' || c==')')
    {
        int st = idx;
        while(idx<S && s[idx]==c) ++idx;
        ret = idx-st;
    }
    else
    {
        ret = s[idx]-'0';
        ++idx;
    }
    return ret;
}


int main()
{
    cin >>s;
    s = "+"+s;
    S = s.size();

    int idx = 0;
    while(idx<S)
    {
        op[ct] = read('o',idx);
        l[ct] = read('(',idx);
        n[ct] = read('x',idx);
        r[ct] = read(')',idx);
        ++ct;
    }

    rep(i,ct)
    {
        printf(" %d %d %d %d\n", op[i],l[i],n[i],r[i]);
    }


    return 0;
}
