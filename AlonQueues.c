//AlonQueues.c
#pragma once

#include "AlonQueues.h"

//----------------------------------------------------------------------
// Static Queues
//----------------------------------------------------------------------

//----------------------------------------------------------------------
//                              Init Queue
//                              ----------
//
// General      : This function initilaizes a queue.
//
// Parameters   : 
//			ptrQueue - A pointer to queue (Queue*)				
//
// Return Value : None.
//
//----------------------------------------------------------------------

void initQueue(Queue* ptrQueue)
{
	ptrQueue->amount = 0;
	ptrQueue->front = 0;
	ptrQueue->rear = 0;

	return;
}

//----------------------------------------------------------------------
//                             Is Queue Empty
//                             --------------
//
// General      : This function checks if the queue is empty.
//
// Parameters   : 
//			ptrQueue - A pointer to queue (Queue*)		
//
// Return Value : Returns TRUE if the queue is empty, else FALSE.
//
//----------------------------------------------------------------------

BOOLEAN isQueueEmpty(Queue* ptrQueue)
{
	return (ptrQueue->amount == 0);
}

//----------------------------------------------------------------------
//                             Insert Queue
//                             ------------
//
// General      : This function inserts a value into a queue.
//
// Parameters   : 
//			ptrQueue - A pointer to queue (Queue*)
//          value    - A value (void*)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void insertQueue(Queue* ptrQueue, TYPE value)
{
	ptrQueue->items[ptrQueue->rear++ % MAXSIZEQUEUE] = value;
	ptrQueue->amount++;

	return;
}

//----------------------------------------------------------------------
//                             Remove Queue
//                             ------------
//
// General      : This function removes a value from a queue.
//
// Parameters   : 
//			ptrQueue - A pointer to queue (Queue*)
//
// Return Value : The value of the first value in the queue.
//
//----------------------------------------------------------------------

TYPE removeQueue(Queue* ptrQueue)
{
	TYPE* returnedValue = NULL;
	if (!isQueueEmpty(ptrQueue))
	{
		returnedValue = ptrQueue->items[ptrQueue->front++ % MAXSIZEQUEUE];
		ptrQueue->amount--;
	}

	return (returnedValue);
}

//----------------------------------------------------------------------
//                             Print Queue
//                             -----------
//
// General      : This function prints a queue.
//
// Parameters   : 
//			ptrQueue - A pointer to queue (Queue*)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void printQueue(Queue* ptrQueue)
{
	int numOfItems = ptrQueue->front % MAXSIZEQUEUE - ptrQueue->rear % MAXSIZEQUEUE;
	TYPE* value;

	for (numOfItems; numOfItems; numOfItems--)
	{
		value = removeQueue(ptrQueue);
		insertQueue(ptrQueue, value);
		printf("%d", value);
	}

	return;
}

//----------------------------------------------------------------------
//                           Num Of Items Queue
//                           ------------------
//
// General      : This function calculates the number of items in queue.
//
// Parameters   : 
//			ptrQueue - A pointer to queue (Queue*)
//
// Return Value : The number of items in a queue.
//
//----------------------------------------------------------------------

int numOfItemsQueue(Queue* ptrQueue)
{
	int numOfItems = ptrQueue->front % MAXSIZEQUEUE - ptrQueue->rear % MAXSIZEQUEUE;

	return (numOfItems);
}

//----------------------------------------------------------------------
//								 Copy Queue
//								 ----------
//
// General      : This function copies one queue into another
//
// Parameters   : 
//			ptrQueueSource - A pointer to queue (Queue*)
//			ptrQueueDestination - A pointer to queue (Queue*)
//
// Return Value : None.
//
//----------------------------------------------------------------------

void copyQueue(Queue* ptrQueueSource, Queue* ptrQueueDestination) {
	if (isQueueEmpty(ptrQueueSource)) return;

	insertQueue(ptrQueueSource, FLAG_VALUE);

	TYPE currentValue = removeQueue(ptrQueueSource);

	while (currentValue != FLAG_VALUE) {
		insertQueue(ptrQueueSource, currentValue);
		insertQueue(ptrQueueDestination, currentValue);
		currentValue = removeQueue(ptrQueueSource);
	}

	return;
}