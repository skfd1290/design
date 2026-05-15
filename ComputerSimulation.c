#include <stdio.h>

struct User {
    int id;
    int startTime;
    int numTransactions;
    int durations[100];
};

int main() {

    int n;

    printf("Enter the number of users: ");
    scanf("%d", &n);

    struct User users[n];

    // Input user details
    for (int i = 0; i < n; i++) {

        printf("Enter data for User %d\n", i + 1);

        printf("Enter user ID: ");
        scanf("%d", &users[i].id);

        printf("Enter starting time: ");
        scanf("%d", &users[i].startTime);

        printf("Enter the number of transactions: ");
        scanf("%d", &users[i].numTransactions);

        printf("Enter the durations of the transactions: ");

        for (int j = 0; j < users[i].numTransactions; j++) {
            scanf("%d", &users[i].durations[j]);
        }
    }

    int currentTime = 0;
    int totalWaitingTime = 0;
    int totalTransactions = 0;

    printf("\nOutput:\n");

    // Simulation
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < users[i].numTransactions; j++) {

            int start;

            // Find start time
            if (currentTime > users[i].startTime)
                start = currentTime;
            else
                start = users[i].startTime;

            int waitingTime = start - users[i].startTime;

            int end = start + users[i].durations[j];

            printf(
                "User %d Transaction %d: Start time: %d End time: %d Waiting time: %d - %d = %d seconds\n",
                users[i].id,
                j + 1,
                start,
                end,
                start,
                users[i].startTime,
                waitingTime
            );

            currentTime = end;

            totalWaitingTime += waitingTime;

            totalTransactions++;
        }
    }

    float averageWaitingTime =
        (float) totalWaitingTime / totalTransactions;

    printf("\nAverage waiting time: %.2f seconds\n",
           averageWaitingTime);

    return 0;
}
