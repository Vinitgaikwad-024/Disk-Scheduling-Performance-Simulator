#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int fcfs(){
    int n, i, head, total_seek = 0;

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    int request[n];
    printf("Enter the disk request sequence:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &request[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nFCFS Disk Scheduling:\n");
    printf("Sequence of movement: %d", head);

    for (i = 0; i < n; i++) {
        printf(" -> %d", request[i]);
        total_seek += abs(request[i] - head);
        head = request[i];
    }

    printf("\nTotal Seek Time = %d", total_seek);
    printf("\nAverage Seek Time = %.2f\n", (float)total_seek / n);

    return 0;
}
void scan(int arr[], int n, int head, int disk_size, int direction) {
    int seek_count = 0, distance, cur_track;
    int temp[n + 1], i, j;

    for (i = 0; i < n; i++) temp[i] = arr[i];
    temp[n] = head;
    n++;

    // Sort the requests
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (temp[i] > temp[j]) {
                int t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }

    int pos;
    for (i = 0; i < n; i++)
        if (temp[i] == head) { pos = i; break; }

    printf("Seek sequence: ");
    if (direction == 1) { // Right
        for (i = pos; i < n; i++) printf("%d ", temp[i]);
        printf("%d ", disk_size - 1);
        for (i = pos - 1; i >= 0; i--) printf("%d ", temp[i]);
    } else { // Left
        for (i = pos; i >= 0; i--) printf("%d ", temp[i]);
        printf("0 ");
        for (i = pos + 1; i < n; i++) printf("%d ", temp[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {82, 170, 43, 140, 24, 16, 190};
    int size = sizeof(arr)/sizeof(arr[0]);
    int head = 50;
    int disk_size = 200;
    int direction = 1; // 1 = Right, 0 = Left

    scan(arr, size, head, disk_size, direction);
    return 0;
}

int clook();
int look();
void cscan(int arr[], int n, int head, int disk_size) {
    int seek_count = 0, i, j;
    int temp[n + 2];

    for (i = 0; i < n; i++) temp[i] = arr[i];
    temp[n] = head;
    temp[n + 1] = disk_size - 1; // end point
    n += 2;

    // Sort
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (temp[i] > temp[j]) {
                int t = temp[i];
                temp[i] = temp[j];
                temp[j] = t;
            }

    int pos;
    for (i = 0; i < n; i++)
        if (temp[i] == head) { pos = i; break; }

    printf("Seek sequence: ");
    for (i = pos; i < n; i++) printf("%d ", temp[i]);
    printf("0 ");
    for (i = 0; i < pos; i++) printf("%d ", temp[i]);
    printf("\n");
}

int main() {
    int arr[] = {82, 170, 43, 140, 24, 16, 190};
    int size = sizeof(arr)/sizeof(arr[0]);
    int head = 50;
    int disk_size = 200;

    cscan(arr, size, head, disk_size);
    return 0;
}

int sstf();
int abs();//
int Sort();//
int Summary();//

int workload(int pattern, int req[], int *n, int *disk_size, int *head)
{
    printf("\nGenerating realistic I/O workload pattern...\n");
    if (pattern == 1) { // Sequential (like video playback)
        *n = 8;
        int temp[] = {10, 20, 30, 40, 50, 60, 70, 80};
        memcpy(req, temp, sizeof(temp));
        *head = 35;
        *disk_size = 200;
    } else if (pattern == 2) { // Random (like web requests)
        *n = 10;
        int temp[] = {176, 79, 34, 60, 92, 11, 41, 114, 7, 124};
        memcpy(req, temp, sizeof(temp));
        *head = 50;
        *disk_size = 200;
    } else { // Mixed workload
        *n = 12;
        int temp[] = {23, 89, 132, 42, 187, 16, 190, 11, 43, 140, 24, 82};
        memcpy(req, temp, sizeof(temp));
        *head = 50;
        *disk_size = 200;
    }
}


int main(){

    int n, ch,req[MAX],dsize,head,pattern;
    printf("-----Enter Choice----\n");

    printf("1 :\t Custom Request Sequence\n");
    printf("0 :\tExit\n");
    scanf("%d",&ch);
    while (1)
    {
        printf("\t DISK SCHEDULING PERFORMENCE SIMULATION\t");
        if (ch==1)
        {
            printf("Enter No of Request : ");
            scanf("%d",&n);
            for (int i = 0; i < n; i++)
            {
                scanf("%d",&req[i]);
            }
            
            printf("DISK SIZE : ");
            scanf("%d",&dsize);
            printf("Enter Head Postion : ");
            scanf("%d",&head);
        }
        else if (ch==0)
        {
            printf("GOODBYE!!");
        }
        else if (ch==2)
        {
             printf("Select Workload Pattern:\n1. Sequential (e.g., video streaming)\n2. Random (e.g., web access)\n3. Mixed (e.g., database system)\nChoice: ");
            scanf("%d", &pattern);
            simulate_workload(pattern, req, &n, &dsize, &head);
        }
        
main
        
    }
    
    int t_fcfs,t_sstf,t_scan,t_cscan,t_look,t_clook;

        int t_fcfs,t_sstf,t_scan,t_cscan,t_look,t_clook;
main

        printf("\nRunning algorithms.......\n");

    printf("\n\n====================== DISK SCHEDULING PERFORMANCE SUMMARY ======================\n");
printf("*------------*------------------------*------------------*\n");
printf("| Algorithm  | Total Head Movement    | Average Seek Time |\n");
printf("*------------*------------------------*------------------*\n");
printf("| %-10s | %-22d | %-16.2f |\n", "FCFS",  t_fcfs,  (float)t_fcfs / n);
printf("| %-10s | %-22d | %-16.2f |\n", "SSTF",  t_sstf,  (float)t_sstf / n);
printf("| %-10s | %-22d | %-16.2f |\n", "SCAN",  t_scan,  (float)t_scan / n);
printf("| %-10s | %-22d | %-16.2f |\n", "C-SCAN", t_cscan, (float)t_cscan / n);
printf("| %-10s | %-22d | %-16.2f |\n", "LOOK",  t_look,  (float)t_look / n);
printf("| %-10s | %-22d | %-16.2f |\n", "C-LOOK", t_clook, (float)t_clook / n);
printf("*------------*------------------------*------------------*\n");
return 0;
}