/******************************
 KMP.cpp  START
******************************/

struct KMP
{
	//テーブル
	vector<int> fail;
	//検索する文字列
	string s;

	KMP(){}
	KMP(const string &s) :s(s)
	{
		int m=s.size();
		fail=vector<int>(m+1);
		int j=fail[0]=-1;
		for(int i=1; i<=m; i++)
		{
			while(j>=0 && s[j]!=s[i-1]) j=fail[j];
			fail[i]=++j;
		}
	}

	//tの中からsを検索
	vector<int> match(const string &t) {
		int n=t.size(), m=p.size();
		vector<int>ret;
		for(int i=0, k=0; i<n; i++)
		{
			while(k>=0 && s[k]!=t[i]) k=fail[k];
			if(++k >= m)
			{
				ret.push_back(i); // match at t[i-m+1 .. i]
				k=fail[k];
			}
		}
		return ret;
	}
};

/******************************
 KMP.cpp  END
******************************/
