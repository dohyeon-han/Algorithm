#include <iostream>
#include <string>
#include <vector>
using namespace std;

//kmp �˰���
//ã�� ���ڿ� ������ �ߺ��Ǵ� �κ��� ã�� ������ �ߺ��Ǵ� ������ pi�� ��ġ ǥ��
//��ü ���ڿ��� ��ġ�� �κ��� ã�� ���� ���ڰ� ��ġ���� ���ο� ���� pi�� ǥ�õ� ������ �ǳʶ��� ����
//���� �����ϱ⿣ �ʹ� ��ƴ�.... �˰��� �� ��ƴ�..

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
				v.push_back(i - p.size() + 2);//i�� 0���� �����̹Ƿ� +1, -p.size()�� ���������� �� ĭ �� ������ +1
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
