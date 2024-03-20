// �����ʿ�
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> dis;
int binarySearch(vector<int> &v, int left, int right, int &C) {
	int answer{};
	while (left <= right) {
		int min = INT_MAX;
		int mid = (left + right) / 2;
		int pre = v[0];
		int cnt = 1;
		for (int i = 1; i < v.size(); i++) {
			if (v[i] - pre == 1) continue; // �� ĭ ���̴� ��ġX
			else if (v[i] - pre < mid) continue; // mid���� ������ �ȵ�
			else {
				cnt++; // ��ġ�Ϸ�
				min = min < v[i] - pre ? min : v[i] - pre;
				pre = v[i];
			}
		}
		
		if (cnt == C) {
			answer = min > mid ? min : mid;
			break;
		}
		else if(cnt > C){
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	return answer;
}

int main() {
	int N{}, C{};
	cin >> N >> C;
	vector<int> v;
	for (int i = 0; i < N; i++) {
		int x{};
		cin >> x;
		v.push_back(x);
	}

	// ����
	sort(v.begin(), v.end());

	cout << binarySearch(v, v[0], v[v.size() - 1], C);

	return 0;
}