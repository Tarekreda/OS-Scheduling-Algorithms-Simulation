#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void insert();
void destroy();
void display();
int rqueue[MAX];
int rear = - 1;
int front = - 1;

typedef struct process
{
    int id;    //Process Number
    int ct;      //cpu Time
    int oct;    //original cpu time
    int iot;    //io Time
    int at;        //arrival time
    int state;     //0 for running 1 for ready 2 for blocked
                   //also initialized by 3 (haven't arrived to system)
    int ft;         // finish time
    int runt;       // running time
    int readyt;     // the time the process became ready
    int pps;
}process;

void swap(int a[], int b, int c) {  // a function used in swapping two numbers in an array
    int temp = a[b];
    a[b] = a[c];
    a[c] = temp;
}
void r_enqueue(int add_process)         // enqueing in the ready queue
{
if (rear == MAX - 1){
    printf("Queue Overflow \n");                    //overflow
}
else
{
    if (front == - 1){     /*If queue is initially empty */
    front = 0;
    }
    rear = rear + 1;
    rqueue[rear] = add_process;
}
}
void r_dequeue()                // dequeue from ready queue FIFO
{
    if (front == - 1 || front > rear)
    {
        printf("Queue Underflow \n");
        return ;
    }
    else
    {
        front = front + 1;
    }
}
void r_display()
{
    int i;
    if (front == - 1)
        printf("Queue is empty \n");
    else
    {
        printf("Queue is : \n");
        for (i = front; i <= rear; i++)
        printf("%d ", rqueue[i]);

        printf("\n");
    }
}

int main()
{
    int algorithm;         //0 for fcfs and 1 for rr
    int i=0;                // i, j , k , m used for different loop iterations
    int j;
    int k=0;
    int m=0;
    int ch_to_num;          // changing charatcer value to int value
    int num_of_processes;       // variable number of processes
    int processes[50];          // array containing all the processes data
    int t=0;
    int qt;
    int cpu_state=0 ; //0 for empty , 1 for full
    int cpu_ut=0;       // for cpu utilization calculations


    char *token;            // opening file variables
    char array[300];
    char file_name[25];
    FILE *fp;

    printf("Enter name of a file you wish to see\n");
    gets(file_name);
    fp = fopen(file_name, "r"); // read mode
   if (fp == NULL)
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }
    fscanf(fp,"%[^\0]s",array);
    char delim[] =" \n";
    token=strtok(array,delim);
    i=0;
    while(token != NULL){
        processes[i]=atoi(token);
        token = strtok(NULL,delim);
        i++;
    }

   fclose(fp);
    int max_count = i;          // defining the arrays needed to keep process data
    num_of_processes=(max_count+1)/4;
    int id[num_of_processes];
    int cpu_time[num_of_processes];
    int io_time[num_of_processes];
    int arrival_time[num_of_processes];

    while(k < max_count){
    id[m]=processes[k];
    cpu_time[m]=processes[1+k];
    io_time[m]=processes[2+k];
    arrival_time[m]=processes[3+k];
    k=k+4;
    m++;
}
    process arr[num_of_processes];
    for(i=0;i<num_of_processes;i++){        // pouring all the arrays data into struct
        arr[i].id = id[i];
        arr[i].ct = cpu_time[i];
        arr[i].oct = cpu_time[i];
        arr[i].iot = io_time[i];
        arr[i].at = arrival_time[i];
        arr[i].state = 3 ;
        arr[i].runt=0;
        arr[i].readyt=0;
        arr[i].pps=0;
    }
//============================= FCFS =======================//
    process l;

    for (i = 0; i < num_of_processes - 1; i++)
    {
        for (j = i + 1; j < num_of_processes; j++)
        {
            //Sorting the processes according to their arrival time
            if (arr[i].at > arr[j].at)
            {
                l = arr[i];
                arr[i] = arr[j];
                arr[j] = l;
            }
            if (arr[i].at == arr[j].at)
            {
                if(arr[i].id > arr[j].id)
                {
                    l = arr[i];
                    arr[i] = arr[j];
                    arr[j] = l;
                }
            }
        }
    }

printf("please state algorithm type : 0 for FCFS 1 for Round Robin ");
scanf("%d",&algorithm);

void sort(int a[],int f, int r){
int temp;
    for (i = f; i <= r - 1; i++)
    {
        for (j = i + 1; j <= r; j++)
        {
            //bubble Sorting an array according to the value of its content
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
void arrived(process arr[],int i,int t){        // when a process arrives to the system
    arr[i].readyt=t;
    arr[i].state=1;
    r_enqueue(arr[i].id);
}
void io_check(process arr[],int i,int t){       // checking if the process finished all its io
    if(arr[i].iot !=0){
      arr[i].state=2;
    }else{
    arr[i].state=3;
    arr[i].ft = t;
    }

}
void io_finish(process arr[],int i,int t){      //when the process finishes the io and needs to have cpu time again
    if(arr[i].ct==0 && arr[i].oct!=0 ){
        arr[i].readyt=t;
        arr[i].ct=arr[i].oct;
        arr[i].oct=0;
        arr[i].state=1;
       r_enqueue(arr[i].id);
    }
}
if(algorithm==0){

    fp = fopen("outputFCFS.txt", "w");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }

}else if(algorithm ==1){
    fp = fopen("outputRR.txt", "w");
    if (fp == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    printf("please insert quantum time :");
    scanf("%d",&qt);

}
while(1){
for(i=0;i<num_of_processes;i++){
if(arr[i].state == 0 ||arr[i].state == 1 ||arr[i].state == 2 ){     // function for process in system
    if(arr[i].state==0){
        arr[i].ct=arr[i].ct-1;
        if(arr[i].ct==0){
            io_check(arr,i,t);
            cpu_state=0;
            arr[i].runt=0;
        }else if(algorithm ==1 && arr[i].ct!=0 && arr[i].runt>=qt){
            arrived(arr,i,t);
            cpu_state=0;
            arr[i].runt=0;
            arr[i].pps=1;
        }
    }else if(arr[i].state==2){
        arr[i].iot=arr[i].iot-1;
        if(arr[i].iot==0){
            io_finish(arr,i,t);
        }
    }
}
}
for(i=0;i<num_of_processes;i++){        // functions for process arrived
    if(arr[i].at == t){
        arrived(arr,i,t);
    }
}

for(i=0;i<num_of_processes;i++){        //if two process arrive at same time , sorting according to id
   for(j=0;j<num_of_processes;j++){
    if(arr[i].id!=arr[j].id){
        if(arr[i].readyt==arr[j].readyt && arr[i].readyt!=0){
            int z,y;
            if(arr[i].id<arr[j].id){
                for(z=front;z<=rear;z++){
                    if(arr[i].id == rqueue[z]){
                        break;
                    }
                }for(y=front;y<=rear;y++){
                        if(arr[j].id == rqueue[y]){
                        break;
                    }
                }
                if (z>y){
                        swap(rqueue,z,y);
                }
 //       arr[i].readyt=0;
//         arr[j].readyt=0;
            }
        }
    }

   }
}

for(i=0;i<num_of_processes;i++){

        if(algorithm==1 && arr[i].pps==1){
         if(arr[i].id==rqueue[front]){
            r_dequeue();
            r_enqueue(arr[i].id);
         }
         arr[i].pps=0;
         break;
        }
}

// sort(rqueue,front,rear);     // a sort function commented in case the lab manual states sorting the queue every iteration
if(cpu_state == 0){
        for(i=0;i<num_of_processes;i++){
            if(arr[i].state==1){
            if(arr[i].id == rqueue[front]){
            r_dequeue();
            arr[i].state=0;
            cpu_state=1;
            break;
            }
        }
        }
}
int flag = 0;
for(i=0;i<num_of_processes;i++){
        if(arr[i].state == 3 && arr[i].ct == 0){
            flag++;
        }
}
if(flag == num_of_processes){
    break;
}else{fprintf(fp,"%d: ",t);}

for(i=0;i<num_of_processes;i++){
        if(arr[i].state==0){
        fprintf(fp,"%d running  ",arr[i].id);
        cpu_ut++;
        arr[i].runt++;
        arr[i].readyt=0;
        }else if(arr[i].state==1){
        fprintf(fp,"%d ready  ",arr[i].id);
        }else if(arr[i].state==2){
        fprintf(fp,"%d blocked  ",arr[i].id);
        }
}
fprintf(fp,"\n");
t++;
}
fprintf(fp,"\nfinishing time: %d",t-1);
fprintf(fp,"\nCPU utilization: %.3f",(float)cpu_ut/(float)t);
fprintf(fp,"\n");
for(i=0;i<num_of_processes;i++){
fprintf(fp,"\nturn around time of process %d is %d",arr[i].id,(arr[i].ft-arr[i].at));
}
fclose(fp);
return 0;
}
