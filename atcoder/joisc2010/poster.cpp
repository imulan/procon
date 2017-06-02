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
    int pw[21];
    pw[0]=1;
    for(int i=1; i<=20; ++i) pw[i] = 2*pw[i-1];

    int n,k;
    cin >>n >>k;

    string s="";
    int i=n;
    while(i>0)
    {
        if(k<=pw[n]/2)
        {
            s += string(pw[i-1],'J')+string(pw[i-1],'O');
            return s;
        }
        else
        {
            s += string(pw[i-1],'I');
            k-=pw[n]/2;
            --n;
        }
        --i;
    }
    s+='J';
    return s;
}

int main()
{
    cout << solve() << endl;
    return 0;
}
