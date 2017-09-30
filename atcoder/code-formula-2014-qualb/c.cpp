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

const string ok = "YES", ng = "NO";

int n;
string a,b;
bool ans = false;

bool check()
{
    rep(i,n)if(a[i]!=b[i]) return false;
    return true;
}

void dfs(int d)
{
    if(d==3) ans |= check();
    else
    {
        vector<int> x;
        rep(i,n)if(a[i]!=b[i]) x.pb(i);

        if(x.size()==0)
        {
            rep(i,n)rep(j,i)
            {
                if(a[i]==a[j])
                {
                    dfs(d+1);
                    i=j=n;
                    break;
                }
            }

            swap(a[0],a[1]);
            dfs(d+1);
            swap(a[0],a[1]);
        }
        else
        {
            for(int i:x)for(int j:x)if(i!=j)
            {
                swap(a[i],a[j]);
                dfs(d+1);
                swap(a[i],a[j]);
            }
        }
    }
}

string solve()
{
    cin >>a >>b;
    n = a.size();

    int ct = 0;
    rep(i,n) ct += (a[i]!=b[i]);

    if(ct>6) return ng;

    dfs(0);
    if(ans) return ok;
    return ng;
}

int main()
{
    cout << solve() << endl;
    return 0;
}
