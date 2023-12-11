#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 100001;
int era[MAX]{}; // 0 : 미탐색, 1 : 소수, 2 : 소수x

// 에라토스테네스의 체
void eratos() {
	for (int i = 2; i <= MAX; i++) {
		if (era[i] != 0) continue;

		for (int j = i; j <= MAX; j += i) {
			if (era[j] == 0) {
				if (j == i) era[j] = 1;
				else era[j] = 2;
			}
		}
	}
}

// 숫자 뒤집기
int reverse(int x) {
	int res{};

	while (x > 0) {
		res *= 10;
		res += x % 10;
		x /= 10;
	}

	return res;
}

// 소수인지 확인
bool isPrime(int x) {
	if (era[x] == 1) return true;
	else return false;
}


int main() {
	int N{};
	cin >> N;

	eratos();

	for (int i = 0; i < N; i++) {
		int num{};
		cin >> num;
		num = reverse(num); // 숫자 뒤집기

		if (isPrime(num)) cout << num << " ";
	}
}