/* this can get the minimum(maximum) value of lines(f_i(x)=ax+b)
when query add and get is monotony(x1<=x2<=x3... or x1>=x2>=x3>=...
and a1<=a2<=a3... or a1>=a2>=a3...), you can use (isMonoticX=true) (O(N+Q))
when add query is monotony, you use (isMonoticX=false) (O((N+Q)logN) */
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
			// if you find maximum val, replace min to max
			b = min(b, lines.back().second);
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
		return lv >= rv;
	}
	// return the minimum(maximum) values among lines
	ll get(ll x){
		if(isMonoticX){
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
