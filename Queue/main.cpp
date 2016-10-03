//
//  LinkQueue.cpp
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

typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}LinkNode;

typedef struct{
    LinkNode *front, *rear;
}LinkQueue;

Status InitQueue(LinkQueue &Q){
    Q.front = Q.rear = new LinkNode();
    if (!Q.front) {
        exit(OVERFLOW);
    }
    Q.front->next = NULL;
    return OK;
}

Status EnQueue(LinkQueue &Q, ElemType a[], int n){
    for (int i = 0; i < n; i++) {
        LinkNode *p = new LinkNode;
        if (!p) {
            exit(OVERFLOW);
        }
        p->data = a[i];
        p->next = NULL;
        Q.rear->next = p;
        Q.rear = p;
    }
    return OK;
}

Status DeQueue(LinkQueue &Q, ElemType e){
    if (Q.front == Q.rear) {
        return ERROR;
    }
    LinkNode *p = new LinkNode;
    p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if (p == Q.rear) {
        Q.rear = Q.front;
    }
    delete p;
    return OK;
}
int ShowQueue(LinkQueue Q){
    LinkNode *p = new LinkNode();
    p = Q.front->next;
    while (p != Q.rear->next) {
        cout<<p->data<<", ";
        p = p->next;
    }
    return OK;
}

int main(int argc, const char * argv[]) {
    LinkQueue Q = *new LinkQueue();
    InitQueue(Q);
    int a[] = {1, 2, 3, 4, 5};
    EnQueue(Q, a, 5);
    int e;
    ShowQueue(Q);
    DeQueue(Q, e);
    ShowQueue(Q);
    cout<<123;
    
}
