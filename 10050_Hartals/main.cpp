/* @JUDGE_ID:  10050  C++  "Hartals" */

/**************
by: Carlos Mera
date: 09/09/2017

**************/
#include <iostream>
#include <cstdlib>



using namespace std;


int main() {

	int T, N, P;

	cin >> T;
	while (T > 0) {
		cin >> N;

		cin >> P;
		int* party_h = (int*)malloc(sizeof(int)*P);

		for (int party = 0; party < P; party++) {
			int i;
			cin >> i;
			party_h[party] = i;
		}

		int days[3650];

		for (int i = 0; i <= N; i++) {
			days[i] = 0;
		}

		for (int party = 0; party < P; party++) {
			int day = party_h[party];
			while (day <= N) {
				if (day % 7 != 6 && day % 7 != 0) {
					days[day]++;
				}
				day += party_h[party];
			}
		}

		int hartals = 0;
		for (int i = 1; i <= N; i++) {
			if (days[i] != 0) {
				hartals++;
			}
		}


		cout << hartals << endl;
		T--;
	}
	return 0;
}
