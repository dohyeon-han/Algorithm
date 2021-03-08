#include <iostream>
#include <string>
#include <vector>
using namespace std;

//kmp 알고리즘
//찾는 문자열 내에서 중복되는 부분을 찾아 이전에 중복되는 곳으로 pi에 위치 표시
//전체 문자열은 겹치는 부분을 찾고 다음 문자가 겹치는지 여부에 따라 pi에 표시된 곳으로 건너뛸지 결정
//말로 설명하기엔 너무 어렵다.... 알고리즘도 꽤 어렵다..

vector<int> getPi(string p) {
	int j = 0;
	vector<int> pi(p.size(), 0);
	for (int i = 1; i < p.size(); i++)
	{
		while (j > 0 && p[i] != p[j]) {
			j = pi[j - 1];
		}
		if (p[i] == p[j]) {
			pi[i] = ++j;
		}
	}
	return pi;
}

vector<int> kmp(string t, string p) {
	int j = 0;
	vector<int> v;
	vector<int> pi = getPi(p);
	for (int i = 0; i < t.size(); i++)
	{
		while (j > 0 && t[i] != p[j]) {
			j = pi[j - 1];
		}
		if (t[i] == p[j]) {
			if (j == p.size() - 1) {
				v.push_back(i - p.size() + 2);//i가 0부터 시작이므로 +1, -p.size()가 시작점보다 한 칸 더 감으로 +1
				j = pi[j];
			}
			else j++;
		}
	}
	return v;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	string t, p;
	getline(cin, t);
	getline(cin, p);
	vector<int> v = kmp(t, p);
	cout << v.size() << '\n';
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << ' ';
	}
}
