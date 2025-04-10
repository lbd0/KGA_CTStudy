#include <iostream>
#include <vector>

using namespace std;

void Merge(vector<int>& v, int left, int mid, int right) {
	int leftsize = mid - left + 1;
	int rightsize = right - mid;
	
	vector<int > L(leftsize), R(rightsize);

	for (int i = 0; i < leftsize; i++) {
		L[i] = v[left + i];
	}

	for (int i = 0; i < rightsize; i++) {
		R[i] = v[mid + 1 + i];
	}

	int i = 0, j = 0;

	int k = left;

	while (i < leftsize && j < rightsize) {
		if (L[i] <= R[j]) {
			v[k] = L[i];
			i++;
		}
		else {
			v[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < leftsize) {
		v[k] = L[i];
		i++;
		k++;
	}

	while (j < rightsize) {
		v[k] = R[j];
		j++;
		k++;
	}

}

void MergeSort(vector<int>& v, int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		MergeSort(v, left, mid);
		MergeSort(v, mid + 1, right);

		Merge(v, left, mid, right);
	}
}

int main() {
	vector<int> v = { 12, 11, 13, 5, 6,7 };
	MergeSort(v, 0, v.size() - 1);

	for (auto n : v) {
		cout << n << endl;
	}
}