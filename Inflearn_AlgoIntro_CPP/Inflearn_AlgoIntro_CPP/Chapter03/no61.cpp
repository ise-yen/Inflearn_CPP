#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int path[11];
int ans{};
void sumSubset(int x, int N, int sum, int M) {
	if (x == N) {
		if (sum == M) {
			ans++;
			for (int i = 0; i < N; i++) {
				cout << path[i] << " ";
			}
			cout << "\n";
		}
		return;
	}

	path[x] = v[x];
	sumSubset(x + 1, N, sum + v[x], M);
	path[x] = 0;
	sumSubset(x + 1, N, sum, M);
	path[x] = -v[x];
	sumSubset(x + 1, N, sum - v[x], M);
}

int main() {
	int N{}, M{};
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int tmp{};
		cin >> tmp;
		v.push_back(tmp);
	}

	sumSubset(0, N, 0, M);

	if (ans == 0) cout << -1;
	else cout << ans;
	return 0;
}