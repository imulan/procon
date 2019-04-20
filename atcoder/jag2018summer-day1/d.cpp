#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int (i)=0;(i)<(int)n;++(i))
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
typedef pair<char,ll> P;

int n;

void solve(){
    stack<P> sta;
    queue<P> que;
    scanf(" %d",&n);
    for(int i=0;i<n;i++){
        char c;
        ll a;
        scanf(" %c %lld",&c,&a);
        // printf("%lld\n",a);
        que.push(P(c,a));
    }
    while(que.size()){
        P p=que.front();
        que.pop();
        if(sta.size()>0 && sta.top().first==p.first){
            P pp=sta.top();
            sta.pop();
            p.second+=pp.second;
        }
        ll v=p.second/3LL;
        if(v>0LL){
            if(que.size() && que.back().first==p.first){
                que.back().second+=v;
            }else{
                que.push(P(p.first,v));
            }
        }
        v=p.second%3LL;
        if(v>0LL){
            sta.push(P(p.first,v));
        }
    }
    ll ans=0;
    while(sta.size()){
        P p=sta.top();
        sta.pop();
        ans+=p.second;
    }
    printf("%lld\n",ans);
}

int main(){
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++){
        solve();
    }


    return 0;
}
