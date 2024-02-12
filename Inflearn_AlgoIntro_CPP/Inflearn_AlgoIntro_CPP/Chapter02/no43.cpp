#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int N{}, M{};
int answer{};

int CntV(int s) {
	int cnt = 1, sum{};
	for (int i = 0; i < N; i++) {
		if (sum + v[i] > s) { // 다음걸 더했을 때 최대보다 크면?
			cnt++; // dvd 개수 추가
			sum = v[i];
		}
		else { // 더해도 되면?
			sum += v[i]; // 추가
		}
	}

	return cnt;
}

int main() {
	cin >> N >> M;
	int lt = 1, rt{}; // lt = 최소 용량, rt = 최대 용량
	for (int i = 0; i < N; i++) {
		int num{};
		cin >> num;
		v.push_back(num); // 비디오 길이
		rt += num; // 최대 용량 갱신
	}

	while (lt <= rt) {
		int mid = (lt + rt) / 2; // 중간 용량값

		if (CntV(mid) <= M) { // dvd 개수가 M이하라면 : 더 줄여도 된다
			answer = mid; // 용량 최소값 갱신
			rt = mid - 1;
		}
		else lt = mid + 1;
	}

	cout << answer;
	return 0;
}