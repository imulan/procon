#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
	string s;
	long n;
	cin >> s >> n;
	
	bool a=false, b=false;	
	
	//multiplication-first
	stack<long> st;
	int now=0;
	long m=0;
	while(now<s.size()){
		if('0'<=s[now] && s[now]<='9') st.push(s[now++]-'0');
		else{
			if(s[now]=='*'){
				long v=st.top();
				st.pop();
				st.push(v*(s[now+1]-'0'));
				now+=2;
			}	
			else now++;
		}		
	}
	while(!st.empty()){
		m+=st.top();
		st.pop();
	}
	
	if(m==n) a=true;
	//printf(" a: m=%ld\n", m);
	
	//left-to-right
	now=0;
	m=0;
	while(now<s.size()){
		if('0'<=s[now] && s[now]<='9') st.push(s[now++]-'0');
		else{
			if(s[now]=='*'){
				long v=st.top();
				st.pop();
				st.push(v*(s[now+1]-'0'));
				now+=2;
			}
			else if(s[now]=='+'){
				long v=st.top();
				st.pop();
				st.push(v+(s[now+1]-'0'));	
				now+=2;	
			}	
		}			
	}
	while(!st.empty()){
		m+=st.top();
		st.pop();
	}
	
	if(m==n) b=true;
	//printf(" b: m=%ld\n", m);
	
	
	if(a&&b) printf("U\n");
	else if(a&&!b) printf("M\n");
	else if(!a&&b) printf("L\n");
	else if(!a&&!b) printf("I\n");
}