#include "board.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#define txPrio 1
#define rxPrio 1
#define QUEUESIZE 2

xQueueHandle queue_handle = NULL;

void tx(void *p) {
	int item = 0;
	while (1) {
		printf("tx() send to queue : ");
		long ok = xQueueSend(queue_handle, &item, 500);
		puts(ok ? "OK" : "FAILED");
		vTaskDelay(200);
	}
}

void rx(void *p) {
	int item = 0;
	while (1) {

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

