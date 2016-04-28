#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stack>
#include <sstream>
#include <string>
using namespace std;

int main(){
	string s;
	while(getline(cin, s)){
		stack<double> st;
		stringstream ss(s);
		string t;	
		double a, b;
		
		while(ss >> t){
			
			if(t == "+"){
				a=st.top();
				st.pop();
				b=st.top();
				st.pop();
				st.push(b+a);
			}
			else if(t == "-"){
				a=st.top();
				st.pop();
				b=st.top();
				st.pop();
				st.push(b-a);
			}
			else if(t == "*"){
				a=st.top();
				st.pop();
				b=st.top();
				st.pop();
				st.push(b*a);				
			}
			else if(t == "/"){
				a=st.top();
				st.pop();
				b=st.top();
				st.pop();
				st.push(b/a);			
			}
			else st.push(atof(t.c_str()));
	
		}
	
		printf("%lf\n", st.top());
		st.pop();
	}
	return 0;
}