#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of users: ";
    cin >> n;

    vector<int> userID(n), startTime(n), numTrans(n);
    vector<vector<int>> durations(n);

    // Input
    for (int i = 0; i < n; i++) {
        cout << "Enter data for User " << i + 1 << endl;

        cout << "Enter user ID: ";
        cin >> userID[i];

        cout << "Enter starting time: ";
        cin >> startTime[i];

        cout << "Enter the number of transactions: ";
        cin >> numTrans[i];

        durations[i].resize(numTrans[i]);

        cout << "Enter the durations of the transactions: ";
        for (int j = 0; j < numTrans[i]; j++) {
            cin >> durations[i][j];
        }
    }

    int current_time = 0;
    double total_waiting_time = 0;
    int total_transactions = 0;

    // USER LEVEL FCFS
    for (int i = 0; i < n; i++) {

        // If CPU is idle, jump to user's start time
        if (current_time < startTime[i]) {
            current_time = startTime[i];
        }

        for (int j = 0; j < numTrans[i]; j++) {

            int start = current_time;
            int end = start + durations[i][j];

            // Waiting time based on user's initial start time
            int waiting = start - startTime[i];

            cout << "User " << userID[i]
                 << " Transaction " << j + 1
                 << ": Start time: " << start
                 << " End time: " << end
                 << " Waiting time: " << start
                 << "-" << startTime[i]
                 << " = " << waiting << " seconds" << endl;

            total_waiting_time += waiting;
            total_transactions++;

            current_time = end; // update system time
        }
    }

    double avg = total_waiting_time / total_transactions;

    cout << fixed << setprecision(2);
    cout << "Average waiting time: " << avg << " seconds" << endl;

    return 0;
}









//java code

import java.util.Scanner;

class User {
    int id;
    int startTime;
    int numTransactions;
    int[] durations;
}

public class ComputerSimulation {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of users: ");
        int n = sc.nextInt();

        User[] users = new User[n];

        // Input user details
        for (int i = 0; i < n; i++) {

            users[i] = new User();

            System.out.println("Enter data for User " + (i + 1));

            System.out.print("Enter user ID: ");
            users[i].id = sc.nextInt();

            System.out.print("Enter starting time: ");
            users[i].startTime = sc.nextInt();

            System.out.print("Enter the number of transactions: ");
            users[i].numTransactions = sc.nextInt();

            users[i].durations = new int[users[i].numTransactions];

            System.out.print("Enter the durations of the transactions: ");

            for (int j = 0; j < users[i].numTransactions; j++) {
                users[i].durations[j] = sc.nextInt();
            }
        }

        int currentTime = 0;
        int totalWaitingTime = 0;
        int totalTransactions = 0;

        System.out.println("\nOutput:");

        // Simulation
        for (int i = 0; i < n; i++) {

            User u = users[i];

            for (int j = 0; j < u.numTransactions; j++) {

                int start = Math.max(currentTime, u.startTime);

                int waitingTime = start - u.startTime;

                int end = start + u.durations[j];

                System.out.println(
                    "User " + u.id +
                    " Transaction " + (j + 1) +
                    ": Start time: " + start +
                    " End time: " + end +
                    " Waiting time: " + start +
                    " - " + u.startTime +
                    " = " + waitingTime + " seconds"
                );

                currentTime = end;

                totalWaitingTime += waitingTime;

                totalTransactions++;
            }
        }

        double averageWaitingTime =
                (double) totalWaitingTime / totalTransactions;

        System.out.printf(
            "\nAverage waiting time: %.2f seconds\n",
            averageWaitingTime
        );

        sc.close();
    }
}
