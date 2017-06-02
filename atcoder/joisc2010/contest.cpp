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

int E[10][1000], S[10][1000],w[10][1000]={};

int main()
{
    int N,M,T,X,Y;
    cin >>N >>M >>T >>X >>Y;

    vector<int> p(M);
    rep(i,M) cin >>p[i];

    fill(E[0],E[10],-1);
    fill(S[0],S[10],-1);

    while(Y--)
    {
        int t,n,m;
        string J;
        cin >>t >>n >>m >>J;
        --n;
        --m;
        if(J[0]=='o') S[m][n]=t;
        else if(J[0]=='c') E[m][n]=t;
        else ++w[m][n];
    }

    rep(i,N)
    {
        int s=0;
        rep(j,M)if(E[j][i]!=-1) s+=max(X,p[j]-(E[j][i]-S[j][i])-120*w[j][i]);
        cout << s << endl;
    }
    return 0;
}
