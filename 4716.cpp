#include <iostream>
#include <algorithm>
using namespace std;

//마음에 안드는 문제, 조건을 너무 대충 알려줌  
//큐브가 상자 밖으로 나올 수 있는지 ex)8*8*4 이면 8*8*8큐브가 가능한 지, 입력된 큐브의 한 변이 n을 넘는 경우가 있는지 등
//큐브의 변이 큰 순으로 상자를 채워 나간다.
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
		prev <<= 3; //큐브를 나눔 - 변이 4인 큐브 하나는 변이 2인 큐브 8개와 같다
		cube = min(p[i].second, (le >> p[i].first) * (wi >> p[i].first) * (he >> p[i].first) - prev); //넣을 수 있는 큐브의 개수
		prev += cube;
		sum += cube;//총 개수

		//상자를 가장 큰 큐브의 단위로 나누고 채울 수 있는 개수를 구함
		//남은 상자의 부피와 채운 큐브의 부피를 하위 큐브의 단위로 나눔
		//어렵다..
	}
	cout << (le * wi * he == prev ? sum : -1);
}