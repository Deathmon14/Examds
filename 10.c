#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 5
struct item{
 int ele;
};
struct cqueue {
 struct item it [MAXSIZE];
 int front;
 int rear;
};
void insertitem(struct cqueue *pq, int x);
int deleteitem(struct cqueue *pq);
void main(){
 struct cqueue cq;
 int x, choice, r;
 cq.front=MAXSIZE-1,cq.rear=MAXSIZE-1;
 do {
 printf("............. MENU........");
 printf("\n 1: INSERT\t 2: REMOVE\t 3: QUIT\n");
 printf("Enter your choice:");
 scanf("%d", &choice);
 switch (choice){ 
 case 1: printf("Enter the item to be inserted:");
 scanf("%d", &x);
 insertitem(&cq,x);
 break;
 case 2: r = deleteitem(&cq);
 printf("The item deleted is %d\n",r);
 break;
 case 3: printf("QUITTING OPERATION QUEUE \n");
 break;
 default :printf("No such option\n");
 }
 }
 while(choice!=3);
}
void insertitem(struct cqueue *pq, int x){ 
 if (pq->rear==MAXSIZE-1) 
 pq->rear=0;
 else
 (pq->rear) ++;
 if (pq->rear==pq->front){
 printf("Circular Queue Overflow\n");;
 exit(1);
 } pq->it [pq->rear].ele=x;
 return;
} 
int deleteitem(struct cqueue *pq){
 if (pq->front==pq->rear){ 
 printf("Queue underflow\n");
 exit(1);
 }
 if(pq->front==MAXSIZE-1)
 pq->front=0;
 else
 (pq->front)++;
 return (pq->it [pq->front].ele);
}
