#include <stdio.h>

void sortDescending(int a[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (a[i] < a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int findMinMachine(int load[], int m) {
    int minIndex = 0;
    for (int i = 1; i < m; i++) {
        if (load[i] < load[minIndex])
            minIndex = i;
    }
    return minIndex;
}

int main() {
    int n, m;
    printf("Enter number of tasks: ");
    scanf("%d", &n);

    printf("Enter number of machines: ");
    scanf("%d", &m);

    int a[n], load[m];

    printf("Enter task times: ");
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    sortDescending(a, n);

    for (int i = 0; i < m; i++) load[i] = 0;

    for (int i = 0; i < n; i++) {
        int idx = findMinMachine(load, m);
        printf("Task (%d) -> Machine %d\n", a[i], idx+1);
        load[idx] += a[i];
    }

    printf("\nFinal Loads:\n");
    for (int i = 0; i < m; i++)
        printf("Machine %d: %d\n", i+1, load[i]);

    return 0;
}
