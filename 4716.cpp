#include <iostream>
#include <algorithm>
using namespace std;

//������ �ȵ�� ����, ������ �ʹ� ���� �˷���  
//ť�갡 ���� ������ ���� �� �ִ��� ex)8*8*4 �̸� 8*8*8ť�갡 ������ ��, �Էµ� ť���� �� ���� n�� �Ѵ� ��찡 �ִ��� ��
//ť���� ���� ū ������ ���ڸ� ä�� ������.
bool cmp(pair<long long, long long> a, pair<long long ,long long>b) {
	return a.first > b.first;
}

int main() {
	long long le,wi,he;
	pair<long long, long long> p[21];
	int n;

	cin >> le >> wi >> he;
	
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> p[i].first >> p[i].second;
	}

	sort(p, p + n, cmp);

	long long sum = 0, prev = 0, cube = 0;
	for (int i = 0; i < n; i++)
	{
		prev <<= 3; //ť�긦 ���� - ���� 4�� ť�� �ϳ��� ���� 2�� ť�� 8���� ����
		cube = min(p[i].second, (le >> p[i].first) * (wi >> p[i].first) * (he >> p[i].first) - prev); //���� �� �ִ� ť���� ����
		prev += cube;
		sum += cube;//�� ����

		//���ڸ� ���� ū ť���� ������ ������ ä�� �� �ִ� ������ ����
		//���� ������ ���ǿ� ä�� ť���� ���Ǹ� ���� ť���� ������ ����
		//��ƴ�..
	}
	cout << (le * wi * he == prev ? sum : -1);
}