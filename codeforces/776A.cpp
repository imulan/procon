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
    string s[2];
    cin >>s[0] >>s[1];
    cout << s[0] << " " << s[1] << endl;

    int n;
    cin >>n;
    while(n--)
    {
        string x[2];
        cin >>x[0] >>x[1];
        if(s[0]==x[0]) s[0]=x[1];
        else if(s[0]==x[1]) s[0]=x[0];
        else if(s[1]==x[0]) s[1]=x[1];
        else if(s[1]==x[1]) s[1]=x[0];

        cout << s[0] << " " << s[1] << endl;
    }

    return 0;
}
