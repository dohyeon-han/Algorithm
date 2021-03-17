#include <iostream>
#include <string>
#include <stack>
#include <queue>
using namespace std;


int main() {
	queue<string> rst;
	stack<string> st;
	stack<double> d;
	string s;
	getline(cin, s);
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ' ') continue;//ºóÄ­ °Ç³Ñ
		else if ('0' <= s[i] && s[i] <= '9') {//½Ç¼ö
			int j = i;
			string num;
			while (true) {
				if (j >= s.size() || s[j] == ' ') break;
				if ('0' <= s[j] && s[j] <= '9' || s[j] == '.')
					num += s[j++];
				else break;
			}
			rst.push(num);
			i = j - 1;
		}
		else {//±âÈ£
			if (s[i] == '(') {
				st.push("(");
			}
			else if (s[i] == ')') {
				while (!st.empty()&&st.top() != "(") {
					rst.push(st.top());
					st.pop();
				}
				st.pop();//(
			}
			else if (s[i] == '*' || s[i] == '/') {
				while (!st.empty() && (st.top() == "*" || st.top() == "/")) {
					rst.push(st.top());
					st.pop();
				}
				if (s[i] == '*') {
					st.push("*");
				}
				else {
					st.push("/");
				}

			}
			else {//+,-
				while (!st.empty() && st.top() != "(") {
					rst.push(st.top());
					st.pop();
				}
				if (s[i] == '+') {
					st.push("+");
				}
				else {
					st.push("-");
				}
				
			}
		}
	}
	while (!st.empty()) {
		rst.push(st.top());
		st.pop();
	}
	while (!rst.empty()) {
		cout << rst.front();
		rst.pop();
		/*string t = rst.front(); rst.pop();
		if (t == "+" || t == "-" || t == "*" || t == "/") {
			double a = d.top(); d.pop();
			double b = d.top(); d.pop();
			if (t == "+") {
				d.push(a + b);
			}
			else if (t == "-") {
				d.push(b - a);
			}
			else if (t == "*") {
				d.push(a * b);
			}
			else if (t == "/") {
				d.push(b / a);
			}
			cout << endl;
		}
		else {
			double a = stod(t);
			d.push(a);*/
		//}
	}
	//cout << d.top();

}