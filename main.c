#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

int absVal(int a) { return (a < 0) ? -a : a; }

void display(char *x, int total, int n) {
    printf("[%s] Total Head Movement: %d | Average Seek Time: %.2f\n",
           x, total, (float)total / n);
}

void Sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1]) {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
}

int fcfs(int req[], int n, int head) {
    int total_seek = 0;
    for (int i = 0; i < n; i++) {
        total_seek += absVal(req[i] - head);
        head = req[i];
    }
    return total_seek;
}

int sstf(int req[], int n, int head) {
    int done[MAX] = {0}, total = 0;
    for (int count = 0; count < n; count++) {
        int min = 1e9, index = -1;
        for (int i = 0; i < n; i++)
            if (!done[i] && absVal(req[i] - head) < min) {
                min = absVal(req[i] - head);
                index = i;
            }
        total += absVal(req[index] - head);
        head = req[index];
        done[index] = 1;
    }
    return total;
}

int scan(int arr[], int n, int head, int disk_size, int direction) {
    int total = 0, i, j, temp[n + 1];
    for (i = 0; i < n; i++) temp[i] = arr[i];
    temp[n] = head;
    n++;
    Sort(temp, n);

    int pos;
    for (i = 0; i < n; i++)
        if (temp[i] == head) { pos = i; break; }

    if (direction == 1) {
        total += (disk_size - 1 - head) + (disk_size - 1 - temp[0]);
    } else {
        total += (head - 0) + (temp[n - 1] - 0);
    }
    return total;
}

int cscan(int arr[], int n, int head, int disk_size) {
    int total = 0, i, j, temp[n + 2];
    for (i = 0; i < n; i++) temp[i] = arr[i];
    temp[n] = head;
    temp[n + 1] = disk_size - 1;
    n += 2;
    Sort(temp, n);

    int pos;
    for (i = 0; i < n; i++)
        if (temp[i] == head) { pos = i; break; }

    total += (disk_size - 1 - head) + (disk_size - 1 - temp[0]);
    return total;
}

int look(int req[], int n, int head, int dir) {
    int total = 0, arr[MAX + 1];
    for (int i = 0; i < n; i++) arr[i] = req[i];
    arr[n++] = head;
    Sort(arr, n);

    int pos;
    for (int i = 0; i < n; i++) if (arr[i] == head) { pos = i; break; }

    if (dir == 1)
        total = (arr[n - 1] - head) + (arr[n - 1] - arr[0]);
    else
        total = (head - arr[0]) + (arr[n - 1] - arr[0]);

    return total;
}

int clook(int req[], int n, int head) {
    int total = 0, arr[MAX + 1];
    for (int i = 0; i < n; i++) arr[i] = req[i];
    arr[n++] = head;
    Sort(arr, n);

    int pos;
    for (int i = 0; i < n; i++) if (arr[i] == head) { pos = i; break; }

    total = (arr[n - 1] - head) + (arr[n - 1] - arr[0]) + (arr[pos - 1] - arr[0]);
    return total;
}

void workload(int pattern, int req[], int *n, int *disk_size, int *head) {
    if (pattern == 1) {
        *n = 8;
        int temp[] = {10, 20, 30, 40, 50, 60, 70, 80};
        memcpy(req, temp, sizeof(temp));
        *head = 35;
        *disk_size = 200;
    } else if (pattern == 2) {
        *n = 10;
        int temp[] = {176, 79, 34, 60, 92, 11, 41, 114, 7, 124};
        memcpy(req, temp, sizeof(temp));
        *head = 50;
        *disk_size = 200;
    } else {
        *n = 12;
        int temp[] = {23, 89, 132, 42, 187, 16, 190, 11, 43, 140, 24, 82};
        memcpy(req, temp, sizeof(temp));
        *head = 50;
        *disk_size = 200;
    }
}

int main() {
    int n, ch, req[MAX], dsize, head, pattern;

    while (1) {
        printf("\n==== DISK SCHEDULING PERFORMANCE SIMULATOR ====\n");
        printf("1. Custom Sequence\n2. Simulate Workload\n0. Exit\nChoice: ");
        scanf("%d", &ch);

        if (ch == 0) {
            printf("Exiting...\n");
            break;
        } else if (ch == 1) {
            printf("Enter number of requests: ");
            scanf("%d", &n);
            printf("Enter request sequence: ");
            for (int i = 0; i < n; i++) scanf("%d", &req[i]);
            printf("Enter disk size: ");
            scanf("%d", &dsize);
            printf("Enter initial head: ");
            scanf("%d", &head);
        } else if (ch == 2) {
            printf("Select workload pattern:\n1. Sequential\n2. Random\n3. Mixed\nChoice: ");
            scanf("%d", &pattern);
            workload(pattern, req, &n, &dsize, &head);
        } else continue;

        int t_fcfs = fcfs(req, n, head);
        int t_sstf = sstf(req, n, head);
        int t_scan = scan(req, n, head, dsize, 1);
        int t_cscan = cscan(req, n, head, dsize);
        int t_look = look(req, n, head, 1);
        int t_clook = clook(req, n, head);

        printf("\n==================== PERFORMANCE SUMMARY ====================\n");
        printf("| Algorithm | Total Movement | Avg Seek Time |\n");
        printf("|------------|----------------|---------------|\n");
        printf("| FCFS       | %14d | %13.2f |\n", t_fcfs, (float)t_fcfs / n);
        printf("| SSTF       | %14d | %13.2f |\n", t_sstf, (float)t_sstf / n);
        printf("| SCAN       | %14d | %13.2f |\n", t_scan, (float)t_scan / n);
        printf("| C-SCAN     | %14d | %13.2f |\n", t_cscan, (float)t_cscan / n);
        printf("| LOOK       | %14d | %13.2f |\n", t_look, (float)t_look / n);
        printf("| C-LOOK     | %14d | %13.2f |\n", t_clook, (float)t_clook / n);
        printf("=============================================================\n");

        // Best algorithm
        int min = t_fcfs;
        char best[20] = "FCFS";
        if (t_sstf < min) { min = t_sstf; strcpy(best, "SSTF"); }
        if (t_scan < min) { min = t_scan; strcpy(best, "SCAN"); }
        if (t_cscan < min) { min = t_cscan; strcpy(best, "C-SCAN"); }
        if (t_look < min) { min = t_look; strcpy(best, "LOOK"); }
        if (t_clook < min) { min = t_clook; strcpy(best, "C-LOOK"); }

        printf("\n🏆 Best Performing Algorithm: %s (Min Total Movement = %d)\n", best, min);
    }

    return 0;
}
