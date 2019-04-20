#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define repl(i,a,b) for(int (i)=(int)(a); (i)<(int)(b); ++(i))
#define rep(i,n) repl(i,0,n)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second

#define dbg(x) cout<<#x<<"="<<x<<endl

#define MAX_N 1000010

int _n,_k;
int ranks[MAX_N+1];
int tmp[MAX_N+1];
int SA[MAX_N+1];
int ISA[MAX_N+1];

bool compare_sa(int i,int j){
    if(ranks[i]!=ranks[j])return ranks[i]<ranks[j];
    else{
        int ri=i+_k<=_n?ranks[i+_k]:-1;
        int rj=j+_k<=_n?ranks[j+_k]:-1;
        return ri<rj;
    }
}

void construct_sa(string s,int *sa){
    _n=s.length();
    for(int i=0;i<=_n;i++){
        sa[i]=i;
        ranks[i]=i<_n?s[i]:-1;
    }
    for(_k=1;_k<=_n;_k*=2){
        sort(sa,sa+_n+1,compare_sa);
        tmp[sa[0]]=0;
        for(int i=1;i<=_n;i++){
            tmp[sa[i]]=tmp[sa[i-1]]+(compare_sa(sa[i-1],sa[i])?1:0);
        }
        for(int i=0;i<=_n;i++){
            ranks[i]=tmp[i];
        }
    }
}

int main(){
    int N;
    string S;
    cin>>N>>S;
    
    int idx=-1;
    rep(i,N){
        if(S[i]=='0'){
            idx=i; break;
        }
    }
    if(idx==-1){
        cout<<"0 0"<<endl;
        return 0;
    }
    
    construct_sa(S,SA);
    int ans=-1;
    for(int i=N;i>=0;i--){
        if(SA[i]>=idx){
            ans=SA[i];
            break;
        }
    }
    cout<<idx<<" "<<ans-idx<<endl;
    return 0;
}

