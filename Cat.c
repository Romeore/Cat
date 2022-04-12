#define _CRT_SECURE_NO_WARNINGS

#define COMMAND_NOT_FOUND   -1
#define TURING_MACHINE_SIZE 100
#define SYMBOL              1
#define END_LOOP_COMMAND    7
#define END_IF_COMMAND      9

#include <string.h>
#include "AlonQueues.h"

char* commands[] = { "MEOW", "meow", "Meow", "meoW", "MeoW", "mEow", "MEow", "meOW", "MeOw","mEoW"};
char turingMachine[TURING_MACHINE_SIZE];
char* memoryLocation;
char copyRegister;

void end_program(char* message) {
	printf("\nError - %s\n", message);
	exit(1);
}

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
	else if (!strcmp(buffer, commands[6])) {
		*commandNumber = 6;
	}
	else if (!strcmp(buffer, commands[7])) {
		*commandNumber = 7;
	}
	else if (!strcmp(buffer, commands[8])) {
		*commandNumber = 8;
	}
	else if (!strcmp(buffer, commands[9])) {
		*commandNumber = 9;
	}
}

void executeCommands(Queue* commandQueuePtr) {

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
				break;
			case 5:
				if (*memoryLocation != '0') {
					copyRegister = *memoryLocation;
				}
				else if (copyRegister != '0') {
					*memoryLocation = copyRegister;
					copyRegister = '0';
				}
				break;
			case 6:
			{
				BOOLEAN foundLoopEndCommand = FALSE;
				Queue tempQueue;
				Queue oneLoopQueue;
				initQueue(&tempQueue);
				initQueue(&oneLoopQueue);
				char timesToExecuteRegister = *memoryLocation;
				while (!isQueueEmpty(commandQueuePtr) && !foundLoopEndCommand) {
					int currentCommand = removeQueue(commandQueuePtr);
					if (currentCommand != END_LOOP_COMMAND) {
						insertQueue(&oneLoopQueue, currentCommand);
					}
					else {
						foundLoopEndCommand = TRUE;
						while (timesToExecuteRegister-- > '0')
						{
							copyQueue(&oneLoopQueue, &tempQueue);
							executeCommands(&tempQueue);
						}
					}
				}

				if (!foundLoopEndCommand) {
					end_program("Missing finish loop instruction");
				}
			}
			break;
			case 7:
				end_program("Missing start loop instruction");

			case 8:
			{
				BOOLEAN foundEndIfCommand = FALSE;
				Queue tempQueue;
				initQueue(&tempQueue);
				while (!isQueueEmpty(commandQueuePtr) && !foundEndIfCommand) {
					int currentCommand = removeQueue(commandQueuePtr);
					if (currentCommand != END_IF_COMMAND) {
						insertQueue(&tempQueue, currentCommand);
					}
					else {
						foundEndIfCommand = TRUE;
						if (*memoryLocation > copyRegister) {
							executeCommands(&tempQueue);
						}
					}
				}

				if (!foundEndIfCommand) {
					end_program("Missing finish if instruction");
				}
				break;
			}
			case 9:
				end_program("Missing start if instruction");
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

	memoryLocation = turingMachine + TURING_MACHINE_SIZE / 2;
	copyRegister = '0';
	memset(turingMachine, '0', TURING_MACHINE_SIZE);

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
