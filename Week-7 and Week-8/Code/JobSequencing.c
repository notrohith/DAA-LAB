#include <stdio.h>

#define N 14

struct Job
{
    int id;
    int deadline;
    int profit;
};

void swap(struct Job *a, struct Job *b)
{
    struct Job temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{

    int profit[N] = {22, 19, 29, 28, 30, 21, 27, 25, 24, 26, 14, 27, 19, 11};
    int deadline[N] = {3, 3, 8, 6, 7, 5, 10, 4, 6, 12, 13, 2, 14, 1};

    struct Job jobs[N];

    for (int i = 0; i < N; i++)
    {
        jobs[i].id = i + 1;
        jobs[i].profit = profit[i];
        jobs[i].deadline = deadline[i];
    }

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < N - i - 1; j++)
        {
            if (jobs[j].profit < jobs[j + 1].profit)
            {
                swap(&jobs[j], &jobs[j + 1]);
            }
        }
    }

    int maxDeadline = 0;
    for (int i = 0; i < N; i++)
    {
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    int slot[maxDeadline];
    int filled[maxDeadline];

    for (int i = 0; i < maxDeadline; i++)
        filled[i] = 0;

    int totalProfit = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = jobs[i].deadline - 1; j >= 0; j--)
        {
            if (filled[j] == 0)
            {
                slot[j] = jobs[i].id;
                filled[j] = 1;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    printf("Selected Jobs \n");
    for (int i = 0; i < maxDeadline; i++)
    {
        if (filled[i] == 1)
            printf("Slot %d -> Job %d\n", i + 1, slot[i]);
    }

    printf("\nMaximum Profit = %d\n", totalProfit);

    return 0;
}