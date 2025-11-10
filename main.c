#include<stdio.h>
#define MAX 100

int display(char *x);

int fcfs(); // VINIT
int scan();
int clook();
int look();
int cscan();
int sstf();
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
int Summary();

int workload();


int main(){

    int n, ch,req[MAX],dsize,head;
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

    



return 0;
}