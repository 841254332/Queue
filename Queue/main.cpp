//
//  main.cpp
//  Queue
//
//  Created by luojiahua on 16/10/3.
//  Copyright © 2016年 luojiahua. All rights reserved.
//

#include <iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXQSIZE 10
#define OVERFLOW -1

typedef int Status;
typedef int ElemType;

typedef struct{
    ElemType *base;
    int front;
    int rear;
}SqQueue;

Status InitQueue(SqQueue &Q){
    Q.base = new ElemType(MAXQSIZE);
    if (!Q.base) {
        exit(OVERFLOW);
    }
    Q.front = Q.rear = 0;
    return OK;
}

int QueueLengh(SqQueue Q){
    return (Q.rear + MAXQSIZE - Q.front) % MAXQSIZE;
}

Status EnQueue(SqQueue &Q, ElemType e[], int n){
    for (int i = 0; i < n; i++) {
        if ((Q.rear+1)%MAXQSIZE == Q.front) {
            return ERROR;
        }
        Q.base[Q.rear] = e[i];
        Q.rear = (Q.rear + 1) % MAXQSIZE;
    }
    return OK;
}

Status DeQueue(SqQueue &Q, ElemType &e){
    if (Q.rear == Q.front) {
        return ERROR;
    }
    e = Q.base[Q.front];
    Q.front = (Q.front + 1) % MAXQSIZE;
    return OK;
}

int ShowQueue(SqQueue Q){
    for (int i = Q.front; i < Q.rear; i++) {
        cout<<i<<":"<<Q.base[i]<<", ";
    }
    cout<<"\n";
    return 0;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    SqQueue Q = *new SqQueue;
    InitQueue(Q);
    int a[] = {1,2,3,4,5};
    EnQueue(Q, a, 5);
    ShowQueue(Q);
    int e;
    DeQueue(Q, e);
    ShowQueue(Q);
    cout << QueueLengh(Q)<<endl;
    return 0;
}
