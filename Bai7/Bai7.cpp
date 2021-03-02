#include <bits/stdc++.h>
#include <omp.h>
using namespace std;
using namespace std::chrono; // namespace count time

static long steps = 1000000000;
double step;

int main() {

    int i,j;
    double x;
    double pi, sum = 0.0;
	step = 1.0/(double) steps;

	int N_THREADS;
	cout << "Input number of threads: ";
	cin >> N_THREADS;

	sum = 0.0;
	// Parallel area
	omp_set_num_threads(N_THREADS);
	
	auto start = high_resolution_clock::now();
	#pragma omp parallel for reduction(+:sum) private(x)
        for (i=0; i < steps; i++) {
            x = (i+0.5)*step;
            sum += 4.0 / (1.0+x*x); 
        }
	
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	
    pi = step * sum;
	cout << "Pi in Parallel: " << pi << " " << endl;
	cout << duration.count() << "us " << endl ;
	ofstream log("log.txt", std::ios_base::app);
	log << N_THREADS << "threads: " << duration.count() << "us" << endl ;
	return 0;
}