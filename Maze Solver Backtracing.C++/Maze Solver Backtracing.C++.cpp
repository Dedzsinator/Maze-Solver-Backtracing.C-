#include <stdio.h>
#include <fstream>
using namespace std;

ifstream f("in.in");
ifstream f1("in2.in");
ofstream g("out.out");

int n, sol[100][100], arr[100][100];

void readin(int x, int arr[100][100]) {
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			f >> arr[i][j];
		}
	}
}

bool solveUntil(int arr[100][100], int x, int y, int sol[100][100]);

void print(int sol[100][100]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			g<<sol[i][j] << " ";
		g<<"\n";
	}
}

bool ok(int arr[100][100], int x, int y) {
	if (x >= 0 && x < n && y >= 0 && y < n && arr[x][y] == 1)
		return true;

	return false;
}

bool solve(int arr[100][100]) {
	readin(n, sol);

	if (solveUntil(arr, 0, 0, sol) == false) {
		g<<"Nincs Megoldas!";
		return false;
	}

	print(sol);
	return true;
}

bool solveUntil(int arr[100][100], int x, int y, int sol[100][100]) {
	if (x == n - 1 && y == n - 1) {
		sol[x][y] = 1;
		return true;
	}

	if (ok(arr, x, y) == true) {
		sol[x][y] = 1;
		if (solveUntil(arr, x + 1, y, sol) == true)
			return true;

		if (solveUntil(arr, x, y + 1, sol) == true)
			return true;

		sol[x][y] = 0;
		return false;
	}

	return false;
}

int main() {

	f >> n;

	readin(n, arr);

	solve(arr);
	return 0;
}