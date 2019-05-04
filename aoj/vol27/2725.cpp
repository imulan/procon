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

const ll INF = LLONG_MAX/3;

// 傾きが講義単調増加であることを仮定
using P = pair<ll,ll>;
struct CHTrick{
	deque<P> lines;
	bool isMonoticX = false;
	CHTrick(bool flag=false){
		isMonoticX = flag;
	}
	// check whether line l2 is useless
	// maybe overflow
	bool check(P l1, P l2, P l3){
		return (long double)(l3.second-l2.second)*(l2.first-l1.first) >= (long double)(l2.second-l1.second)*(l3.first-l2.first);
	}
	// add line(y=ax+b)
	void add(ll a, ll b){
		if(lines.size()>0 && lines.back().first==a){
			// for maximum val, replace min to max
			b = max(b, lines.back().second);
			lines.pop_back();
		}
		P line(a,b);
		while(lines.size()>=2 && check(*(lines.end()-2),lines.back(),line)){
			lines.pop_back();
		}
		lines.push_back(line);
	}
	// return the value of f_i(x)
	ll f(int i, ll x){
		return lines[i].first*x + lines[i].second;
	}
	ll f(P line, ll x){
		return line.first*x + line.second;
	}
	// minimum -> (lv>=rv), maximum ->(lv<=rv)
	bool comp(ll lv, ll rv){
		return lv <= rv;
	}
	// return the minimum(maximum) values among lines
	ll get(ll x){
		if(isMonoticX){
            if(lines.empty()) return -INF;
			while(lines.size()>=2 && comp(f(0,x),f(1,x))){
				lines.pop_front();
			}
			return f(0,x);
		}else{
			int low = -1, high = lines.size()-1;
			while(high-low>1){
				int mid=(high+low)/2;
				if(comp(f(mid,x),f(mid+1,x))) low = mid;
				else high = mid;
			}
			return f(high,x);
		}
	}
};

int main(){
    int n,T;
    cin >>n >>T;

    vector<int> t(n),p(n),f(n);
    vector<pair<int,int>> v(n);
    rep(i,n){
        cin >>t[i] >>p[i] >>f[i];
        v[i] = {f[i], i};
    }
    sort(all(v));

    ll ans = 0;
    vector<CHTrick> cht(T+1, CHTrick(true));
    for(const auto &pp:v){
        int idx = pp.se;

        vector<ll> dp(T+1, -INF);
        dp[t[idx]] = p[idx];

        for(int j=T; j>=0; --j){
            int nj = j+t[idx];
            if(nj<=T){
                ll vv = cht[j].get(f[idx]) + p[idx] - f[idx]*f[idx];
                dp[nj] = max(dp[nj], vv);
            }
        }

        rep(j,T+1){
            if(dp[j] > -INF) cht[j].add(2*f[idx], dp[j]-f[idx]*f[idx]);
            ans = max(ans, dp[j]);
        }
    }
    cout << ans << endl;
    return 0;
}
