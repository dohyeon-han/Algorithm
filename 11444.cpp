#include<iostream>
#define MOD 1000000007
using namespace std;

//행렬을 이용한 피보나치 수 계산
// Fn+1 = |1 1| * |Fn  | ==> |Fn+1 Fn  | = |1 1|^n
// Fn	  |1 0|	  |Fn-1|	 |Fn   Fn-1|   |1 0|
void op(long long(* a)[2], long long(* b)[2]) {
	long long tmp[2][2];
	tmp[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % MOD;
	tmp[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % MOD;
	tmp[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % MOD;
	tmp[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % MOD;
	a[0][0] = tmp[0][0];
	a[0][1] = tmp[0][1];
	a[1][0] = tmp[1][0];
	a[1][1] = tmp[1][1];
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);
	long long n, matrix[2][2] = { {1,1}, {1,0} }, tmp[2][2], ans[2][2] = { {1,0},{0,1} };

	cin >> n;
	
	while (n > 0) {
		if (n % 2 == 1) {//나머지를 계산
			op(ans, matrix);
		}
		op(matrix, matrix);
		n /= 2;
	}
	cout << ans[0][1];
}