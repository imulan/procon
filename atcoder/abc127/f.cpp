#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i=0;i<(int)(n);++i)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout<<#x" = "<<((x))<<endl
template<class T,class U> ostream& operator<<(ostream& o, const pair<T,U> &p){o<<"("<<p.fi<<","<<p.se<<")";return o;}
template<class T> ostream& operator<<(ostream& o, const vector<T> &v){o<<"[";for(T t:v){o<<t<<",";}o<<"]";return o;}

int main(){
    int q;
    cin >>q;

    priority_queue<ll> Am;
    priority_queue<ll, vector<ll>, greater<ll>> Ap;
    ll sm=0, sp=0;
    ll B = 0;

    rep(i,q){
        int tp;
        cin >>tp;
        if(tp==1){
            ll a,b;
            cin >>a >>b;

            if(Am.empty()){
                Am.push(a);
                sm += a;
            }
            else{
                if(Am.size() == Ap.size()){
                    ll t = Ap.top();
                    if(a < t){
                        Am.push(a);
                        sm += a;
                    }
                    else{
                        Am.push(t);
                        sm += t;
                        Ap.pop();
                        sp -= t;
                        Ap.push(a);
                        sp += a;
                    }
                }
                else{
                    assert(Am.size() == Ap.size()+1);
                    ll t = Am.top();
                    if(t < a){
                        Ap.push(a);
                        sp += a;
                    }
                    else{
                        Ap.push(t);
                        sp += t;
                        Am.pop();
                        sm -= t;
                        Am.push(a);
                        sm += a;
                    }
                }
            }
            B += b;
        }
        else{
            ll x = Am.top();

            ll ans = sp - sm + B;
            if(Am.size() > Ap.size()) ans += x;

            // dbg(vector<ll>(all(Am)));
            // dbg(vector<ll>(all(Ap)));
            cout << x << " " << ans << "\n";
        }
    }

    return 0;
}
