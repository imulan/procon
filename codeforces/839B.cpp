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
    int n,k;
    cin >>n >>k;
    vector<int> a(k);
    rep(i,k) cin >>a[i];

    sort(all(a),greater<int>());

    int f = n, t = 2*n, o = 0;
    rep(i,k)
    {
        while(a[i]>0)
        {
            if(a[i]>2)
            {
                if(f>0) --f;
                else t-=2;

                a[i] -= 4;
            }
            else
            {
                int del = 2;
                if(a[i]==2)
                {
                    if(t>0) --t;
                    else
                    {
                        if(f>0)
                        {
                            --f;
                            ++o;
                        }
                        else
                        {
                            if(o>0)
                            {
                                --o;
                                del = 1;
                            }
                            else return "NO";
                        }
                    }
                }
                else
                {
                    if(o>0) --o;
                    else
                    {
                        if(f>0)
                        {
                            --f;
                            ++t;
                        }
                        else
                        {
                            if(t>0) --t;
                            else return "NO";
                        }
                    }
                }

                a[i] -= del;
            }

            if(f<0 || t<0) return "NO";
        }
    }

    return "YES";
}

int main()
{
    cout << solve() << endl;
    return 0;
}
