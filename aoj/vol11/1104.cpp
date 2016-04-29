#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
	while(1){
		int a, b;
		scanf(" %d %d", &a, &b);
		if(a==0) break;
		
		string s;
		int dx[4]={0,1,0,-1}, dy[4]={1,0,-1,0};
		int dir=0;
		int x=1, y=1;
		
		while(getline(cin, s)){
			stack<int> st;
			
			if(s=="STOP") break;
			else if(s[0]=='R') dir=(dir+1)%4;
			else if(s[0]=='L') dir=(dir-1+4)%4;
			else if(s[0]=='F'){
				st.push(s[8]-'0');
				for(int i=9; i<s.size(); ++i){
					int v=st.top();
					st.pop();
					st.push(10*v+s[i]-'0');
				}
				int k=st.top();
				st.pop();
				
				x+=k*dx[dir];
				y+=k*dy[dir];
				
				if(x<1) x=1;
				if(x>a) x=a;
				if(y<1) y=1;
				if(y>b) y=b;
				
			}
			else if(s[0]=='B'){
				st.push(s[9]-'0');
				for(int i=10; i<s.size(); ++i){
					int v=st.top();
					st.pop();
					st.push(10*v+s[i]-'0');		
				}
				int k=st.top();
				st.pop();
				
				x-=k*dx[dir];
				y-=k*dy[dir];

				if(x<1) x=1;
				if(x>a) x=a;
				if(y<1) y=1;
				if(y>b) y=b;
				
			}
		}
		
		printf("%d %d\n", x, y);
	}
}