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
    int n,h;
    cin >>n >>h;

    vector<string> s(n);
    vector<int> t(n);
    rep(i,n) cin >>s[i] >>t[i];

    int ss = 0, idx = 0;
    int succ = 0, total = 0;
    int miss = 0;
    while(ss<n)
    {
        cout << "? " << s[ss] << '\n';
        fflush(stdout);

        char c;
        cin >>c;

        char f = s[ss][idx];
        if('A'<=f && f<='Z') f = f-'A'+'a';

        ++total;
        if(f == c)
        {
            s[ss][idx] = '_';

            ++succ;
            ++idx;
        }
        else ++miss;

        if(idx==s[ss].size() || miss>t[ss])
        {
            if(miss>t[ss]) --h;

            ++ss;
            idx = 0;
            miss = 0;
        }

        if(h==0) break;
    }

    if(h>0)
    {
        int R = 1000*succ/total;
        printf("! Game Clear %d.%d\n", R/10, R%10);
        fflush(stdout);
    }
    else
    {
        printf("! Game Over\n");
        fflush(stdout);
    }
    return 0;
}
