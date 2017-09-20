/* @JUDGE_ID: 837 C++  "Light and Transparencies" */

/**************
by: Carlos Mera
date: 19/09/2017

**************/
#include <algorithm>
#include <cstdio>



using namespace std;

int main() {
	int test, nl, flag = 0;

	scanf_s("%d", &test);
	while (test--) {
		if (flag == 0) {
			flag = 1;
		}
		else {
			printf("\n");
		}
		scanf_s("%d", &nl);
		int number_intervals;
		double** segments = new double*[nl];
		for (int i = 0; i < nl; i++) {
			segments[i] = new double[5];
		}
		number_intervals = 2 * nl;
		double* inv = new double[number_intervals];
		double* seg = new double[number_intervals];
		double* a_coef = new double[number_intervals];
		int posTem = 0;
		for (int i = 0; i < nl; i++) {
			double x1, x2, y1, y2, r;
			scanf_s("%lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &r);

			segments[i][0] = x1;
			segments[i][1] = y1;
			segments[i][2] = x2;
			segments[i][3] = y2;
			segments[i][4] = r;

			if (x1 < x2) {
				seg[posTem] = x1;
				inv[posTem] = x1;
				seg[posTem + 1] = x2;
				inv[posTem + 1] = x2;
				a_coef[posTem] = r;
				a_coef[posTem + 1] = r;
			}
			else {
				seg[posTem] = x2;
				inv[posTem] = x2;
				seg[posTem + 1] = x1;
				inv[posTem + 1] = x1;
				a_coef[posTem] = r;
				a_coef[posTem + 1] = r;
			}
			posTem += 2;
		}

		sort(inv, inv + number_intervals);

		printf("%d\n", number_intervals + 1);
		printf("-inf %.3f 1.000\n", inv[0]);
		for (int i = 0; i < number_intervals - 1; i++) {
			double light = 1.0;
			for (int k = 0; k < number_intervals - 1; k+=2) {
				if (inv[i] >= seg[k] && inv[i + 1] <= seg[k + 1]) {
					light *= a_coef[k];
				}
			}
			printf("%.3f %.3f %.3f\n", inv[i], inv[i + 1], light);
		}
		printf("%.3f +inf 1.000\n", inv[number_intervals-1]);
	}
	return 0;
}
