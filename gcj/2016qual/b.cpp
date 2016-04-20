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

int main()
{
	int T;
	cin >>T;
	rep(t,T)
	{
		string s;
		cin >>s;

		string dst="";
		rep(i,s.size()) dst+="+";

		int ct=0;

		int idx=s.size()-1;
		while(idx>=0 && s[idx]=='+') --idx;

		if(idx!=-1)
		{
			while(1)
			{
				if(s[0]=='-')
				{
					//ひっくり返す
					++ct;
					reverse(s.begin(),s.begin()+idx+1);
					rep(i,idx+1)
					{
						if(s[i]=='+') s[i]='-';
						else s[i]='+';
					}
					if(s==dst) break;
					else while(idx>=0 && s[idx]=='+') --idx;
				}
				else
				{
					int b=0;
					while(s[b]=='+') ++b;

					//ひっくり返す
					++ct;
					reverse(s.begin(),s.begin()+b);
					rep(i,b)
					{
						if(s[i]=='+') s[i]='-';
						else s[i]='+';
					}
					if(s==dst) break;
					else while(idx>=0 && s[idx]=='+') --idx;
				}

				//std::cout <<"  "<< s << std::endl;
			}
		}

		printf("Case #%d: %d\n",t+1,ct);
	}
	return 0;
}
