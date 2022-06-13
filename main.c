#include <stdio.h>
#include <stdlib.h>
#include<time.h>

#define SERVICE_PERIOD 480
#define MIN_SERVICE_TIME 1
#define MAX_SERVICE_TIME 4
#define MIN_ARRIVAL_TIME 0
#define MAX_ARRIVAL_TIME 3

struct queueNode {
  int arrival_time;
  struct queueNode *nextPtr;
};

typedef struct queueNode QueueNode;
typedef QueueNode *QueueNodePtr;

void printQueue(QueueNodePtr currentPtr);
int isEmpty(QueueNodePtr headPtr);
int dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr);
void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, int value);
int generate_time(int minTime, int maxTime);

int main(void) {
  srand(time(NULL));
  QueueNodePtr headPtr = NULL;  
  QueueNodePtr tailPtr = NULL;  

  int service_time_performed = 0;
  int arrival_time = 0;
  int total_waiting_time = 0;

  int client_arrival_time = 0;
  
  while(arrival_time < SERVICE_PERIOD){
    client_arrival_time = generate_time(MIN_ARRIVAL_TIME, MAX_ARRIVAL_TIME);
    arrival_time += client_arrival_time;
    enqueue(&headPtr, &tailPtr, arrival_time);
  }

  int client_service_time = 0;
  int client_waiting_time = 0;
  int count_clients = 0;
  int min_waiting_time = 0;
  int max_waiting_time = 0;
  while(headPtr != NULL){
    client_service_time = generate_time(MIN_SERVICE_TIME, MAX_SERVICE_TIME);
    printf("Service time performed: %d\n", service_time_performed);
    printf("Client service time generated: %d\n", client_service_time);
    printQueue(headPtr);
    client_arrival_time = dequeue(&headPtr, &tailPtr);
    if(service_time_performed > client_arrival_time){
      client_waiting_time = service_time_performed - client_arrival_time;
      total_waiting_time += client_waiting_time;
      if(client_waiting_time > max_waiting_time){
        max_waiting_time = client_waiting_time;
      }
      if(client_waiting_time < min_waiting_time){
        min_waiting_time = client_waiting_time;
      }
    }
    else{
      service_time_performed = client_arrival_time;
    }
    service_time_performed += client_service_time;
    count_clients ++;
    printf("Client waiting time: %d\n\n", client_waiting_time);
  }
  printQueue(headPtr);
  printf("Total clients: %d\n", count_clients);
  printf("Total waiting time: %d\n", total_waiting_time);
  printf("Min waiting time: %d\n", min_waiting_time);
  printf("Max waiting time: %d\n", max_waiting_time);
  printf("Mean waitint time: %d", (total_waiting_time / count_clients));
  
}

void enqueue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr, int value){
  QueueNodePtr newPtr = malloc(sizeof(QueueNode));
  if(newPtr != NULL){
    newPtr -> arrival_time = value;
    newPtr -> nextPtr = NULL;

    if(isEmpty(*headPtr)){
      *headPtr = newPtr;
    }
    else{
      (*tailPtr) -> nextPtr = newPtr;
    }
    *tailPtr = newPtr;
  }
  else{
    printf("%d not inserted. No memory available. \n", value);
  }
}

int dequeue(QueueNodePtr *headPtr, QueueNodePtr *tailPtr){
  if(isEmpty(*headPtr)){
    printf("queue is empty!");
  }
  else{
    int value = (*headPtr) -> arrival_time;
    QueueNodePtr tempPtr = *headPtr;
    *headPtr = (*headPtr) -> nextPtr;

    if(*headPtr == NULL){
      *tailPtr = NULL;
    }
    free(tempPtr);
    return value;
  }
}

void printQueue(QueueNodePtr currentPtr){
  if(currentPtr == NULL){
    puts("queue is empty!");
  }
  else{
    while(currentPtr != NULL){
      printf("%d --> ", currentPtr -> arrival_time);
      currentPtr = currentPtr -> nextPtr;
    }
    puts("NULL\n");
  }
}

int isEmpty(QueueNodePtr headPtr){
  return headPtr == NULL;
}



int generate_time(int minTime, int maxTime){
  return minTime + (rand() % (maxTime-minTime+1));
}