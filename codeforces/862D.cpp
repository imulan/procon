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

inline int query(const string &s)
{
    cout << "? " << s << endl;
    fflush(stdout);
    int v;
    cin >>v;
    return v;
}

int main()
{
    int n;
    cin >>n;

    int p[2]={};

    string z(n,'0');
    int all_zero = query(z);

    z[0]='1';
    int one = query(z);

    char c;
    string b;
    if(one > all_zero)
    {
        p[0]=1;
        c = '1';
        b = string(n,'0');
    }
    else
    {
        p[1]=1;
        c = '0';
        b = string(n,'1');
    }

    int base = query(b);

    int l = 0, r = n-1;
    while(r-l>1)
    {
        int m = (l+r)/2;
        string t = b;

        rep(i,m+1) t[i]=c;

        int q = query(t);
        if(q == base+m+1) l=m;
        else r=m;
    }
    p[c-'0']=r+1;

    printf("! %d %d\n", p[0],p[1]);
    return 0;
}
