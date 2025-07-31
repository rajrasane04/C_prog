// FCFS Algorithm

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

void disp(int val[],int n){
    for(int i=0;i<n;i++){
        printf("%d ",val[i]);
    }
}

void sortAll(int at[],int p[],int bt[],int n){  
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(at[j] > at[j+1]) {
                int temp = at[j];
                at[j] = at[j+1];
                at[j+1] = temp;
                
                temp = bt[j];
                bt[j] = bt[j+1];
                bt[j+1] = temp;
                
                temp = p[j];
                p[j] = p[j+1];
                p[j+1] = temp;
            }
        }
    }
}

void getstwtfttat(int st[],int wt[],int ft[],int bt[],int at[],int tat[],int n){
    st[0] = at[0];

    for(int i=1;i<n;i++){
        st[i] = st[i-1] + bt[i-1];
    }

    for(int i=0;i<n;i++){
        wt[i] = st[i] - at[i];
    }

    for(int i=0;i<n;i++){
        ft[i] = st[i] + bt[i];
    }

    for(int i=0;i<n;i++){
        tat[i] = ft[i] - at[i];
    }
}

void ganttchart(int p[],int n,int at[],int bt[],int st[]){

    printf("\n ---- ---- ---- \n");
    printf("|");
    for(int i=0;i<n;i++){
        printf("P%d  |",p[i]);
    }
    printf("\n ---- ---- ---- ----\n");
    
    for(int i=0;i<n;i++){
        printf("%d   ",st[i]);
    }
    
    int a = st[n-1] + bt[n-1];

    printf("%d",a);
    
    printf("\n");
}

void dispchart(int p[],int bt[],int at[],int st[],int wt[],int ft[],int tat[],int n){
    printf(" ---- ---- ---- ----\n");
    printf("| Process | BT | AT | ST | WT | FT | TAT |\n");
    printf(" ---- ---- ---- ----\n");
    for(int i=0;i<n;i++){
        printf("| P%d      | %d  | %d  | %d  | %d  | %d  | %d  |\n", p[i], bt[i],   
               at[i], st[i], wt[i], ft[i], tat[i]);
    }
    printf(" ---- ---- ---- ----\n");
    printf("\n");
}

void dispavg(int wt[],int tat[],int n){
    int wtsum=0;
    for(int i=0;i<n;i++){
        wtsum = wtsum + wt[i];
    }
    printf("Total Waiting Time = %d/%d\n", wtsum,n);

    // float wtavg = wtsum / n;

    int tatsum=0;
    for(int i=0;i<n;i++){
        tatsum = tatsum + tat[i];
    }

    printf("Total Turn Around Time = %d/%d\n", tatsum,n);

    // float tatavg = tatsum / n;

    // printf("Average Waiting Time = %f\n", wtavg);
    // printf("Average Turn Around Time = %f\n", tatavg);
}

void main(){
    int n;

    printf("Enter how many processes : \n");
    scanf("%d",&n);

    int p[n],bt[n],at[n],st[n],wt[n],ft[n],tat[n];

    printf("Enter %d processes :- \n",n);
    for(int i=0;i<n;i++){
        printf("Enter process %d : \n",i+1);
        scanf("%d",&p[i]);
    }

    printf("Now enter their burst time :- \n");
    for(int i=0;i<n;i++){
        printf("Enter bt for process %d : \n",i+1);
        scanf("%d",&bt[i]);
    }

    printf("Now enter their arrival time :- \n");
    for(int i=0;i<n;i++){
        printf("Enter at for process %d : \n",i+1);
        scanf("%d",&at[i]);
    }
    sortAll(at, p, bt, n);  // Sort processes based on arrival time

    printf("Sorted Process :");
    disp(p,n);
    printf("\nSorted bt : ");
    disp(bt,n);
    printf("\nSorted at : ");
    disp(at,n);
    

    getstwtfttat(st,wt,ft,bt,at,tat,n);

    printf("\nStart time : ");
    disp(st,n);

    printf("\nFinish Time : ");
    disp(ft,n);

    printf("\nTurn Around Time : ");
    disp(tat,n);
    
    ganttchart(p, n, at, bt,st);

    dispchart(p, bt, at, st, wt, ft, tat, n);

    dispavg(wt, tat, n);
}