#include <bits/stdc++.h>
#include <omp.h>
using namespace std;
using namespace std::chrono; // namespace count time

const int M = 8;
const int N = 8000000;

float a[M][N];
float b[N][1];
float c[M][1];

int main() {
    // 8000000x8 8x1
    ifstream f1("Bai8MxN_3.txt");
	ifstream f2("Bai8Nx1_3.txt");
	for (int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++){
            f1 >> a[i][j];
        }
	}
    for (int i = 0; i < N; i++) {
        for(int j = 0; j < 1; j++){
            f2 >> b[i][j];
        }
	}
    while (true){
		int N_THREADS;
		cout << "Input number of threads: ";
		cin >> N_THREADS;

		// Parallel area
		omp_set_num_threads(N_THREADS);
		
		auto start = high_resolution_clock::now();
		#pragma omp parallel for default(none) shared(a,b,c)
		for (int i = 0; i < M; ++i) {
			for (int j = 0; j < 1; ++j) {
				for (int k = 0; k < N; ++k) {
					c[i][j] += a[i][k] * b[k][j];
				}
			}
		}
		
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		
		ofstream f3("Bai8MxN_output.txt");
		for (int i = 0; i < M; i++) {
			for(int j = 0; j < 1; j++){
				f3 << c[i][j] << " ";
			}
			f3 << "\n";
		}
		cout << duration.count() << "us " << endl ;
		ofstream log("log.txt", std::ios_base::app);
		log << N_THREADS << "threads: " << duration.count() << "us" << endl ;
	}
	
	return 0;
}