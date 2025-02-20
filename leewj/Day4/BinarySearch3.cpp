// https://www.acmicpc.net/problem/1654

#include <iostream>
#include <vector>

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int k, n;
	int max = 0;

	std::cin >> k >> n;

	std::vector<int> length(k);
	for (int i = 0; i < k; ++i) {
		std::cin >> length[i];
		if (max < length[i]) {
			max = length[i];
		}
	}

	long long left = 1;
	long long right = max;
	long long mid = 0;
	long long answer = 0;

	while (left <= right) {
		mid = (left + right) / 2;

		long long LAN = 0;

		for (int i = 0; i < length.size(); ++i) {
			LAN += length[i] / mid;
		}

		if (LAN < n) {
			right = mid - 1;
		}
		else if (LAN >= n) {
			answer = mid;
			left = mid + 1;
		}
	}

	std::cout << answer;

	return 0;
}