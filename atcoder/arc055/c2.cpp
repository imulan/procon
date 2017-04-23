#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

struct RollingHash{
    static const int MD = 3;
    const vector<ll> hash_base{1009,1021,1013};
    const vector<ll> hash_mod{1000000009,1000000007,1000000021};

    int n;
    vector<ll> hs[MD], pw[MD];

    RollingHash(){}
    RollingHash(const string &s){
        n = s.size();
        for(int i=0; i<MD; ++i){
            hs[i].assign(n+1,0);
            pw[i].assign(n+1,0);
            hs[i][0] = 0;
            pw[i][0] = 1;
            for(int j=0; j<n; ++j){
                pw[i][j+1] = pw[i][j]*hash_base[i] % hash_mod[i];
                hs[i][j+1] = (hs[i][j]*hash_base[i]+s[j]) % hash_mod[i];
            }
        }
    }

    ll hash_value(int l, int r, int i){
        return ((hs[i][r] - hs[i][l]*pw[i][r-l])%hash_mod[i]+hash_mod[i])%hash_mod[i];
    }

    // 1-index
    bool match(int l1, int r1, int l2, int r2){
        bool ret = true;
        for(int i=0; i<MD; ++i) ret &= (hash_value(l1-1,r1,i) == hash_value(l2-1,r2,i));
        return ret;
    }
};

int main()
{
    string s;
    cin >>s;

    RollingHash RH(s);
    ll ans = 0;

    int S=s.size();
    for(int i=S/2+2; i<=S-1; ++i)if(s[0]==s[i-1])
    {
        int la=0,ra=i+1;
        while(ra-la>1)
        {
            int m=(la+ra)/2;

            bool valid=false;
            if(m<i && i+m-1<=S) valid = RH.match(1,m,i,i+m-1);

            if(valid) la = m;
            else ra=m;
        }

        int lc=0,rc=i+1;
        while(rc-lc>1)
        {
            int m=(lc+rc)/2;

            bool valid=false;
            if(i-m>0 && S-(m-1)>=i) valid = RH.match(i-m,i-1,S-(m-1),S);

            if(valid) lc = m;
            else rc=m;
        }

        int L=max(1,S-i+1-lc), R=min(la,S-i+1-1);
        ans += max(0,R-L+1);
    }

    cout << ans << endl;
    return 0;
}
