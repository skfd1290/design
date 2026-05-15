#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <iomanip>

double generatePolishTime(std::mt19937& rng) {
    std::normal_distribution<double> dist(20.0, 7.0);
    double t;
    do {
        t = dist(rng);
    } while (t < 5);
    return t;
}

int argmin(const std::vector<double>& arr) {
    return std::min_element(arr.begin(), arr.end()) - arr.begin();
}

double simulate(int numMachines, int N) {
    std::mt19937 rng(std::random_device{}());
    std::uniform_real_distribution<double> uniformDist(0.0, 200.0);

    std::vector<double> workerAvail(10, 0.0);
    std::vector<double> machineAvail(numMachines, 0.0);
    double totalWait = 0;
    int itemCount = 0;

    while (itemCount < N) {
        int w = argmin(workerAvail);
        double workerStart = workerAvail[w];

        double assemblyTime = 100 + uniformDist(rng);
        double polishTime = generatePolishTime(rng);

        double assemblyDone = workerStart + assemblyTime;

        int k = argmin(machineAvail);
        double machineStart = std::max(assemblyDone, machineAvail[k]);

        double waitTime = machineStart - assemblyDone;

        totalWait += waitTime;
        itemCount++;

        machineAvail[k] = machineStart + polishTime;
        workerAvail[w] = machineAvail[k];
    }

    return totalWait / N;
}

int main() {
    int N = 10000;

    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Machines: 1 | Average wait: " << simulate(1, N) << " seconds\n";
    std::cout << "Machines: 2 | Average wait: " << simulate(2, N) << " seconds\n";
    std::cout << "Machines: 3 | Average wait: " << simulate(3, N) << " seconds\n";

    return 0;
}