#include "board.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#define txPrio 2
#define rxPrio 1
#define QUEUESIZE 2
#define TIMEOUT 10

xQueueHandle queue_handle = NULL;

void tx(void *p) {
	int item = 0;
	while (1) {
		printf("tx() send to queue : ");
		// Sender item til queue, hvis der ikke er plads i queue failer den efter timeout
		long ok = xQueueSend(queue_handle, &item, TIMEOUT);
		puts(ok ? "OK" : "FAILED");
		vTaskDelay(50);
	}
}

void rx(void *p) {
	int item = 0;
	while (1) {
		// Recieve vil vente på at der kommer et item i queue indtil timout, hvorefter den failer
		if (xQueueReceive(queue_handle, &item, TIMEOUT)) {
			printf("rx() Got item from queue\n");
		} else {
			printf("rx() failed to get an item within %d ticks\n", TIMEOUT);
		}
	}
}

int main(void) {

	setvbuf(stdout, 0, _IONBF, 0);
	setvbuf(stdin, 0, _IONBF, 0);

	queue_handle = xQueueCreate(QUEUESIZE, sizeof(int));

	xTaskCreate(tx, (signed char * ) "tx", 1024, NULL, txPrio, NULL);
	xTaskCreate(rx, (signed char * ) "rx", 1024, NULL, rxPrio, NULL);

	vTaskStartScheduler();

	/* Should never arrive here */
	return 1;
}

