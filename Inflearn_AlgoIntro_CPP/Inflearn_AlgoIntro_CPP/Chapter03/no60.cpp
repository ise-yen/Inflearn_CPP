#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
vector<bool> isVisit;
bool isSame = false;
void subset(int x, int N) {
	if (x >= N) {
		int sum1{}, sum2{};
		for (int i = 0; i < N; i++) {
			if (isVisit[i]) {
				sum1 += v[i];
			}
			else {
				sum2 += v[i];
			}
		}

		if (sum1 == sum2) isSame = true;
		return;
	}

	isVisit[x] = true;
	subset(x + 1, N);
	
	isVisit[x] = false;
	subset(x + 1, N);
}

int main() {
	int N{};
	cin >> N;
	isVisit.resize(N, false);

	for (int i = 0; i < N; i++) {
		int tmp{};
		cin >> tmp;
		v.push_back(tmp);
	}

	subset(0, N);

	if (isSame) cout << "YES";
	else cout << "NO";
}