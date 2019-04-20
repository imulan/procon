#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define repl(i,a,b) for(int (i)=(int)(a);(i)<(int)(b);++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back

const int hash_base = 1009;
const int hash_mod = 1000000009;

struct RollingHash{
    static const int MD = 1;
    // static const vector<ll> hash_base, hash_mod;

    int n;
    int *hs, *pw;

    RollingHash(){}
    RollingHash(const string &s){
        n = s.size();
        hs = new int[n+1];
        pw = new int[n+1];

        hs[0] = 0;
        pw[0] = 1;
        rep(j,n){
            pw[j+1] = (ll)pw[j]*hash_base % hash_mod;
            hs[j+1] = ((ll)hs[j]*hash_base+s[j]) % hash_mod;
        }
    }

    // 1-index
    int hash_value(int l, int r){
        return (( (ll)hs[r] - (ll)hs[l]*pw[r-l])%hash_mod+hash_mod) % hash_mod;
    }

    // bool match(int l1, int r1, int l2, int r2){
    //     bool ret = true;
    //     rep(i,MD) ret &= (hash_value(l1-1,r1,i) == hash_value(l2-1,r2,i));
    //     return ret;
    // }

    int calc(int l, int r){
        return (int)hash_value(l-1,r);
    }
};
// const vector<ll> RollingHash::hash_base{1009};
// const vector<ll> RollingHash::hash_mod{1000000009};

typedef pair<int,int> P;
typedef pair<P ,P> RP;

#define M 100

int N,Q;
string w[100001];
string p[100001],s[100001];
map<P,int> cnts[M+1][M+1];
vector<int> ls;
vector<RollingHash> rs;
unordered_map<int,bool> qhash;

int main(){
    cin.tie(0);ios::sync_with_stdio(false);

    cin>>N>>Q;
    rep(i,N){
        cin>>w[i];
        int l=w[i].size();
        RollingHash wh=RollingHash(w[i]);
        /*
        repl(l1,1,min(l+1,M+1)){
            repl(l2,1,min(l+1,M+1)){
                cnts[P(wh.calc(1,l1),wh.calc(l-l2+1,l))]++;
            }
        }*/
        if(l>M){
            ls.push_back(l);
            rs.push_back(wh);
        }
    }
    rep(i,Q){
        cin>>p[i]>>s[i];
        int pl=p[i].size(),sl=s[i].size();
        RollingHash ph=RollingHash(p[i]);
        RollingHash sh=RollingHash(s[i]);

        qhash[ph.calc(1,pl)]=true;
        qhash[sh.calc(1,sl)]=true;
    }
    rep(i,N){
        int l=w[i].size();
        RollingHash wh=RollingHash(w[i]);

        repl(l1,1,min(l+1,M+1)){
            if(qhash.find(wh.calc(1,l1))==qhash.end())continue;
            repl(l2,1,min(l+1,M+1)){
                if(qhash.find(wh.calc(l-l2+1,l))==qhash.end())continue;
                cnts[l1][l2][P(wh.calc(1,l1),wh.calc(l-l2+1,l))]++;
            }
        }
    }
    rep(i,Q){
        int pl=p[i].size(),sl=s[i].size();
        RollingHash ph=RollingHash(p[i]);
        RollingHash sh=RollingHash(s[i]);

        int res=0;
        if(p[i].size()<=M&&s[i].size()<=M){
            if(cnts[pl][sl].find(P(ph.calc(1,pl),sh.calc(1,sl)))!=cnts[pl][sl].end())res+=cnts[pl][sl][P(ph.calc(1,pl),sh.calc(1,sl))];
        }else{
            int pc=ph.calc(1,pl);
            int sc=sh.calc(1,sl);
            rep(j,rs.size()){
                if(ls[j]<pl||ls[j]<sl)continue;
                if(rs[j].calc(1,pl)==pc&&rs[j].calc(ls[j]-sl+1,ls[j])==sc)res++;
            }
        }
        cout<<res<<"\n";
    }

    return 0;
}
