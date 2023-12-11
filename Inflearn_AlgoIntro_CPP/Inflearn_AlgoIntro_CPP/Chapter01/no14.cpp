#include <iostream>
#include <cmath>

using namespace std;

const int MAX = 100001;
int era[MAX]{}; // 0 : ��Ž��, 1 : �Ҽ�, 2 : �Ҽ�x

// �����佺�׳׽��� ü
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

// ���� ������
int reverse(int x) {
	int res{};

	while (x > 0) {
		res *= 10;
		res += x % 10;
		x /= 10;
	}

	return res;
}

// �Ҽ����� Ȯ��
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
		num = reverse(num); // ���� ������

		if (isPrime(num)) cout << num << " ";
	}
}