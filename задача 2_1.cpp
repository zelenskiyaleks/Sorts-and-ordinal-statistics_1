#include <iostream>
#include <stdint.h>
#include <stdio.h>
#include <vector>
using namespace std;
using std::cout;
using std::endl;
void Merge(vector<int>& A, int start, int middle, int end) {
	int size = end - start + 1;
	int* vectMerge = new int[size];
	int ind_start = start;
	int ind_start_2 = middle;
	for (int j = 0; j < size; j++) {
		if (A[ind_start] <= A[ind_start_2]) {
			vectMerge[j] = A[ind_start];
			if (ind_start != middle - 1) {
				ind_start++;
			}
			else {
				for (int i = j + 1; i < size; i++) {
					vectMerge[i] = A[start + i];
				}
				j = size;
			}
		}
		else {
			vectMerge[j] = A[ind_start_2];
			if (ind_start_2 != end) {
				ind_start_2++;
			}
			else {
				for (int i = j + 1; i < size; i++) {
					vectMerge[i] = A[start + i - end + middle - 1];
				}
				j = size;
			}
		}
	}
	for (int j = start; j <= end; j++) {
		A[j] = vectMerge[j - start];
	}
	delete[] vectMerge;
}

void Mergesort(vector<int>& A, int start, int end) {
	if (start == end) {
		return;
	}
	else {
		int middle = (start + end) / 2;
		Mergesort(A, start, middle);
		Mergesort(A, middle + 1, end);
		Merge(A, start, middle + 1, end);
	}
}
int main()
{
	int n;
	cin >> n;
	int k;
	cin >> k;
	vector <int> v(2 * k); //исходный вектор
	int schetchik = n / k;
	if (schetchik > 0) {
		for (int j = 0; j < k; j++) {
			int ii = 0;
			cin >> ii;
			v[j] = ii;
		}
	}
	Mergesort(v, 0, k - 1);
	if (schetchik > 1) {
		for (int i = 1; i < schetchik; i++) {
			for (int j = 0; j < k; j++) {
				int ii = 0;
				cin >> ii;
				v[k + j] = ii;
			}
			Mergesort(v, k, 2 * k - 1);
			Merge(v, 0, k, 2 * k - 1);
			for (int jj = 0; jj < k; jj++) {
				cout << v[jj] << " ";
				v[jj] = v[jj + k];
			}
		}
	}
	if (n % k > 0) {
		int d = n % k;
		for (int j = 0; j < d; j++) {
			int ii = 0;
			cin >> ii;
			v[k + j] = ii;
		}
		Mergesort(v, k, k + d - 1);
		Merge(v, 0, k, k + d - 1);
		for (int jj = 0; jj < k + d; jj++) {
			cout << v[jj] << " ";
		}
	}
	else {
		for (int jj = 0; jj < k; jj++) {
			cout << v[jj] << " ";
		}
	}
	return 0;
}