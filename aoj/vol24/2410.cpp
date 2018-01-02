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
    int n;
    cin >>n;
    vector<string> s(n);
    rep(i,n) cin >>s[i];

    vector<int> w(n);
    rep(i,n)rep(j,n) w[i]+=(s[i][j]=='o');

    vector<int> v;
    rep(i,n)rep(j,w[i]) v.pb(i+1);
    int V = v.size();
    // dbg(v);

    random_device rnd;
    mt19937 mt(rnd());
    uniform_int_distribution<> randV(0,V-1);

    int a = v[randV(mt)];
    rep(i,1000)
    {
        printf("%d\n", a); fflush(stdout);

        int judge_ai_hand;
        scanf("%d", &judge_ai_hand);

        if(s[a-1][judge_ai_hand-1]=='x') a = v[randV(mt)];
    }

    return 0;
}
