#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

vector<int> factor(int n)
{
    vector<int> ret;
    for(int i=1; i*i<=n; ++i)
    {
        if(n%i==0)
        {
            ret.pb(i);
            if(i != n/i) ret.pb(n/i);
        }
    }
    sort(all(ret));
    return ret;
}

string solve()
{
    string s;
    cin >>s;

    int S=s.size();
    vector<int> divisor = factor(S);

    for(const auto &d:divisor)
    {
        bool valid=true;
        string t=s;
        int num=S/d;

        rep(i,d)
        {
            bool zero=false, one=false;
            rep(j,num)
            {
                zero |= (s[j*d+i]=='0');
                one |= (s[j*d+i]=='1');
            }

            if(zero && one)
            {
                valid = false;
                break;
            }
            else if(one)
            {
                rep(j,num) t[j*d+i] = '1';
            }
            else
            {
                rep(j,num) t[j*d+i] = '0';
            }
        }

        if(valid) return t;
    }
    assert(false);
}

int main()
{
    cout << solve() << endl;
    return 0;
}
