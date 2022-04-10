//AlonQueues.h
#pragma once

#define _CRT_SECURE_NO_WARNINGS

#define BOOLEAN       unsigned short
#define TRUE          1
#define FALSE         0
#define EMPTY         -1
#define MAXSIZEQUEUE  1000
#define TYPE          int

#include <stdio.h>
#include <malloc.h>

typedef struct Queue {
	TYPE items[MAXSIZEQUEUE];
	int   front;
	int   rear;
	int   amount;
} Queue;

BOOLEAN isQueueEmpty(Queue* ptrQueue);

void initQueue(Queue* ptrQueue);

void insertQueue(Queue* ptrQueue, TYPE value);

TYPE removeQueue(Queue* ptrQueue);
