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

const int LIM = 300;
const int H = 700;
const int INF = 1000000001;

const int P = 2000;

int solve()
{
    int n;
    cin >>n;
    vector<int> a(n);
    rep(i,n) cin >>a[i];

    vector<bool> used(P);
    rep(i,n)if(a[i]<P) used[a[i]]=true;
    set<int> os;
    rep(i,P)if(!used[i]) os.insert(i);

    for(int i=n; i<=LIM; ++i)
    {
        bool valid = true;

        vector<int> h(H,-1);
        rep(j,n) h[j+i-n]=a[j];
        for(int j=i; j<H; ++j) h[j]=INF+j;

        set<int> s(os);

        rep(loop,i-n)
        {
            int val = INF+191919;
            int idx = -1;

            rep(j,LIM)if(h[j]==-1)
            {
                if(h[2*j+1]>=0 && h[2*j+2]>=0)
                {
                    if(val>min(h[2*j+1],h[2*j+2])-1)
                    {
                        val = min(h[2*j+1],h[2*j+2])-1;
                        idx = j;
                    }
                }
            }

            assert(idx!=-1);
            if(val<0)
            {
                valid = false;
                break;
            }

            auto itr = s.upper_bound(val);
            if(itr==s.begin())
            {
                valid = false;
                break;
            }
            else
            {
                --itr;
                h[idx] = *itr;
                s.erase(itr);
            }
        }

        if(valid)
        {
            rep(j,LIM)
            {
                if(h[j]>min(h[2*j+1],h[2*j+2])) valid = false;
            }
            if(valid) return i;
        }
    }
    return -1;
}

int main()
{
    cout << solve() << endl;
    return 0;
}
