#define _CRT_SECURE_NO_WARNINGS

#define COMMAND_NOT_FOUND -1
#define TURING_MACHINE_SIZE 100
#define SYMBOL 1

#include <string.h>
#include "AlonQueues.h"

char* commands[] = { "MEOW", "meow", "Meow", "meoW", "MeoW", "mEow"};

void searchForCommand(char* buffer, int* commandNumber) {

	if (!strcmp(buffer, commands[0])) {
		*commandNumber = 0;
	}
	else if (!strcmp(buffer, commands[1])) {
		*commandNumber = 1;
	}
	else if (!strcmp(buffer, commands[2])) {
		*commandNumber = 2;
	}
	else if (!strcmp(buffer, commands[3])) {
		*commandNumber = 3;
	}
	else if (!strcmp(buffer, commands[4])) {
		*commandNumber = 4;
	}
	else if (!strcmp(buffer, commands[5])) {
		*commandNumber = 5;
	}
}

void executeCommands(Queue* commandQueuePtr) {

	char turingMachine[TURING_MACHINE_SIZE];
	char* memoryLocation;
	char copyRegister;
	
	memoryLocation = turingMachine + TURING_MACHINE_SIZE / 2;
	copyRegister = '0';
	memset(turingMachine, '0', TURING_MACHINE_SIZE);

	while (!isQueueEmpty(commandQueuePtr)) {
		switch (removeQueue(commandQueuePtr)) {
			case 0:
				(*memoryLocation)++;
				break;
			case 1:
				(*memoryLocation)--;
				break;
			case 2:
				memoryLocation++;
				break;
			case 3:
				memoryLocation--;
				break;
			case 4:
				printf("%c", *memoryLocation);
			case 5:
				if (*memoryLocation != '0') {
					copyRegister = *memoryLocation;
				}
				else if (copyRegister != '0') {
					*memoryLocation = copyRegister;
					copyRegister = '0';
				}
		}
	}
}

int main(int argc, char* argv[]) {
	Queue commandQueue;
	char currentSymbol;
	FILE* file;
	char buffer[5];
	int currentCommand;

	initQueue(&commandQueue);
	file = fopen(argv[1], "rb");
	currentCommand = COMMAND_NOT_FOUND;
	buffer[4] = '\0';

	if (file) {
		while (fread(&currentSymbol, sizeof(char), SYMBOL, file) == SYMBOL) {
			buffer[3] = currentSymbol;
			searchForCommand(buffer, &currentCommand);
			if (currentCommand != COMMAND_NOT_FOUND) {
				insertQueue(&commandQueue, currentCommand);
				memset(buffer, 0, 4);
				currentCommand = COMMAND_NOT_FOUND;
			}
			else {
				buffer[0] = buffer[1];
				buffer[1] = buffer[2];
				buffer[2] = buffer[3];
			}
		}
	}

	executeCommands(&commandQueue);

	return 0;
}
