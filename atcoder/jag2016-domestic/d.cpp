#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define each(itr,c) for(__typeof(c.begin()) itr=c.begin(); itr!=c.end(); ++itr)
#define all(x) (x).begin(),(x).end()
#define mp make_pair
#define pb push_back
#define fi first
#define se second

typedef pair<int,int> pi;

struct f
{
	int x; //aの山の先頭を指す
	int y; //bの山の先頭を指す
	int p; //その前にパスされた回数
	int t; //a,bのターン(0/1)
	stack<pi> s; //場の状態

	bool operator < (const f & tar) const
	{
		if(x<tar.x) return true;
		if(x>tar.x) return false;
		if(y<tar.y) return true;
		if(y>tar.y) return false;
		if(p<tar.p) return true;
		if(p>tar.p) return false;
		if(t<tar.t) return true;
		if(t>tar.t) return false;
		if(s<tar.s) return true;
		if(s>tar.s) return false;

		return false;
	}
};

int n,m;
vector<int> a,b;

map<f,int> d;

int rec(const f &now)
{
	if(d.find(now)!=d.end()) return d[now];

	//printf("call %d, %d, %d, %d \n",now.x,now.y,now.p,now.t);

	int ret;
	if(now.t==0)
	{
		//自分のターン
		ret=-100000000;

		if(now.x==n)
		{//パスしか出来ない
			stack<pi> st=now.s;

			if(st.empty())
			{
				if(now.p==1) ret=max(ret,0);
				else ret=max(ret,rec(f{now.x,now.y,1,1,st}));
			}
			else
			{
				//得点計算
				int score=0;
				//妨害カードが出たか
				bool p1=false;
				bool p2=false;
				while(!st.empty())
				{
					pi card=st.top();
					st.pop();
					if(card.se==0)
					{
						if(card.fi>0 && !p2) score+=card.fi;
						else if(card.fi==-1) p1=true;
					}
					else
					{
						if(card.fi>0 && !p1) score-=card.fi;
						else if(card.fi==-1) p2=true;
					}
				}

				//printf("score=%d\n", score);
				ret=max(ret,rec(f{now.x,now.y,0,1,st})+score);
			}

		}
		else
		{//置くか、パスするかを選ぶ
			//置く
			stack<pi> st=now.s;
			st.push(pi(a[now.x],0));
			ret=max(ret,rec(f{now.x+1,now.y,0,1,st}));

			//パス
			st=now.s;
			if(st.empty())
			{
				if(now.p==1) ret=max(ret,0);
				else ret=max(ret,rec(f{now.x,now.y,1,1,st}));
			}
			else
			{
				//得点計算
				int score=0;
				//妨害カードが出たか
				bool p1=false;
				bool p2=false;
				while(!st.empty())
				{
					pi card=st.top();
					st.pop();
					if(card.se==0)
					{
						if(card.fi>0 && !p2) score+=card.fi;
						else if(card.fi==-1) p1=true;
					}
					else
					{
						if(card.fi>0 && !p1) score-=card.fi;
						else if(card.fi==-1) p2=true;
					}
				}

				//printf("score=%d\n", score);
				ret=max(ret,rec(f{now.x,now.y,0,1,st})+score);
			}

		}
	}
	else
	{
		//相手のターン
		ret=100000000;
		if(now.y==m)
		{//パスしか出来ない
			stack<pi> st=now.s;
			if(st.empty())
			{
				if(now.p==1) ret=min(ret,0);
				else ret=min(ret,rec(f{now.x,now.y,1,0,st}));
			}
			else
			{
				//得点計算
				int score=0;
				//妨害カードが出たか
				bool p1=false;
				bool p2=false;
				while(!st.empty())
				{
					pi card=st.top();
					st.pop();
					if(card.se==0)
					{
						if(card.fi>0 && !p2) score+=card.fi;
						else if(card.fi==-1) p1=true;
					}
					else
					{
						if(card.fi>0 && !p1) score-=card.fi;
						else if(card.fi==-1) p2=true;
					}
				}

				//printf("score=%d\n", score);
				ret=min(ret,rec(f{now.x,now.y,0,0,st})+score);
			}

		}
		else
		{//置くか、パスするかを選ぶ
			//置く
			stack<pi> st=now.s;
			st.push(pi(b[now.y],1));
			ret=min(ret,rec(f{now.x,now.y+1,0,0,st}));

			//パス
			st=now.s;
			if(st.empty())
			{
				if(now.p==1) ret=min(ret,0);
				else ret=min(ret,rec(f{now.x,now.y,1,0,st}));
			}
			else
			{
				//得点計算
				int score=0;
				//妨害カードが出たか
				bool p1=false;
				bool p2=false;
				while(!st.empty())
				{
					pi card=st.top();
					st.pop();
					if(card.se==0)
					{
						if(card.fi>0 && !p2) score+=card.fi;
						else if(card.fi==-1) p1=true;
					}
					else
					{
						if(card.fi>0 && !p1) score-=card.fi;
						else if(card.fi==-1) p2=true;
					}
				}

				//printf("score=%d\n", score);
				ret=min(ret,rec(f{now.x,now.y,0,0,st})+score);
			}

		}
	}

	//printf(" %d, %d, %d, %d : ret %d\n",now.x,now.y,now.p,now.t,ret);

	return d[now]=ret;
}

int main()
{
	cin >>n >>m;
	a.resize(n);
	b.resize(m);
	rep(i,n) cin >>a[i];
	rep(i,m) cin >>b[i];
	std::cout << rec(f{0,0,0,0,stack<pi>()}) << std::endl;
	return 0;
}
