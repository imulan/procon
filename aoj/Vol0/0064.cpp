#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
	string s;
	int ans=0;
	stack<int> st;
	while(getline(cin, s)){
		int i=0;	
		while(i<s.size()){
			
			if(s[i]>='0' && s[i]<='9') st.push(s[i++]-'0');
			else{++i; continue;}
			
			while(i<s.size() && s[i]>='0' && s[i]<='9'){
				int tmp=st.top();
				st.pop();
				int a=s[i]-'0';
				st.push(tmp*10+a);
				++i;
			}
			ans+=st.top();
			st.pop();
		}
		//printf("%d\n", ans);
	}
	printf("%d\n", ans);
}