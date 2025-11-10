#include<stdio.h>
#define MAX 100

void display(char *x,int total, int n){
    printf("\n[%s] Total Head Movement: %d | Average Seek Time: %.2f\n",
           x, total, (float)total / n);
}
int fcfs(); // VINIT
int scan();//vinit
int clook(int req[],int n,int head){

     int total = 0, arr[MAX + 1];
    for (int i = 0; i < n; i++) arr[i] = req[i];
    arr[n++] = head;
    sort(arr, n);

    int pos;
    for (int i = 0; i < n; i++) if (arr[i] == head) { pos = i; break; }

    total = (arr[n - 1] - head) + (arr[n - 1] - arr[0]) + (arr[pos - 1] - arr[0]);
    display("C-LOOK", total, n - 1);
    return total;

}
int look(int req[],int n,int head){

    int dir;        
    printf("enter Direction \n1 : UP\n2 : DOWN\n ");

    scanf("%d",&dir);
    int total = 0, arr[MAX + 1];
    for (int i = 0; i < n; i++) arr[i] = req[i];
    arr[n++] = head;
    sort(arr, n);

    int pos;
    for (int i = 0; i < n; i++) if (arr[i] == head) { pos = i; break; }

    if (dir == 1)
        total += (arr[n - 1] - head) + (arr[n - 1] - arr[0]);
    else
        total += (head - arr[0]) + (arr[n - 1] - arr[0]);

    display("LOOK", total, n - 1);
    return total;


}
int cscan();//
int sstf(int req[], int n, int head) {
    int done[MAX] = {0}, total = 0;
    for (int count = 0; count < n; count++) {
        int min = 1e9, index = -1;
        for (int i = 0; i < n; i++)
            if (!done[i] && absolute(req[i] - head) < min) {
                min = absolute(req[i] - head);
                index = i;
            }
        total += absolute(req[index] - head);
        head = req[index];
        done[index] = 1;
    }
    display("SSTF", total, n);
    return total;
}

int abs(int a){
    if(a<0){
        return -a;
    }
    else{
        return a;
    }

}
int Sort(int a[],int n){

for (int i = 0; i < n-1; i++)
{
    for (int j = 0; j < n-i-1; j++)
    {
        if (a[j]>a[j+1])
        {
            int t=a[j];
            a[j]=a[j+1];
            a[j+1]=t;
        }
        
    }
    
}


}


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
        
        int t_fcfs,t_sstf,t_scan,t_cscan,t_look,t_clook;

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

      int min = t_fcfs;
        char best[20] = "FCFS";
        if (t_sstf < min) { min = t_sstf; strcpy(best, "SSTF"); }
        if (t_scan < min) { min = t_scan; strcpy(best, "SCAN"); }
        if (t_cscan < min) { min = t_cscan; strcpy(best, "C-SCAN"); }
        if (t_look < min) { min = t_look; strcpy(best, "LOOK"); }
        if (t_clook < min) { min = t_clook; strcpy(best, "C-LOOK"); }

        printf("\n🏆 Best Performing Algorithm: %s (Minimum Total Head Movement = %d)\n", best, min);
 


        
    }
    



    

return 0;
}