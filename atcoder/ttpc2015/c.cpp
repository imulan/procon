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
	string s;
	cin >>s;

	string base="kayama";
	string ans="";

	int i=0;
	while(i<s.size())
	{
		if(s[i]=='o')
		{
			int ct=0;
			while(i+ct<s.size() && s[i+ct]=='o') ++ct;
			//printf("ct=%d\n",ct);

			if(ct>=3 && i+ct+5<s.size() && s.substr(i+ct,6)==base)
			{
				if(ct%3==0) ans+="Oo";
				else if(ct%3==1) ans+="o";
				else ans+="O";

				ans+=base;
				i+=ct+6;
			}
			else
			{
				for(int j=i; j<min((int)s.size(),i+ct); ++j)
					ans+=s[j];
				i+=ct;
			}
		}
		else ans+=s[i++];

	}

	std::cout << ans << std::endl;
	return 0;
}
