#include <iostream>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

map<string, int> arr;
string arr2[100001];

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m;
	string s;
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		cin >> s;
		arr2[i] = s;
		arr.insert(pair<string, int>(s, i + 1));

	}
	
	for (int i = 0; i < m; i++)
	{
		cin >> s;
		if (isdigit(s[0]) > 0) {//숫자
			int a = stoi(s);
			cout << arr2[a - 1] << '\n';
		}
		else {//문자
			cout << arr.find(s)->second << '\n';
		}
	}
}
