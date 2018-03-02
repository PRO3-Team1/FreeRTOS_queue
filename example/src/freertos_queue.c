#include "board.h"
#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"

#define txPrio 1
#define rxPrio 2
#define QUEUESIZE 2
#define TIMEOUT 10

xQueueHandle queue_handle = NULL;

void tx(void *p) {
	//int item = 0;
	CAN_MSG_T item;
	item.ID=14;
	item.DLC=8;

	for(int i=0 ; i<8 ; i++)
				{
					item.Data[i]=173;
				}

	while (1) {
		printf("tx() send to queue : ");
		// Sender item til queue, hvis der ikke er plads i queue failer den efter timeout
		long ok = xQueueSend(queue_handle, &item, TIMEOUT);
		puts(ok ? "OK" : "FAILED");
		vTaskDelay(10);
	}
}

void rx(void *p) {
	//int item = 0;
	CAN_MSG_T item;
	while (1) {
		// Recieve vil vente på at der kommer et item i queue indtil timout, hvorefter den failer
		if (xQueueReceive(queue_handle, &item, TIMEOUT)) {
			printf("rx() Got item from queue\n");
			printf("ID: %d\n",item.ID);
			printf("DLC: %d\n",item.DLC);

			for(int i=0 ; i<8 ; i++)
			{
				printf("%d\n",item.Data[i]);
			}

		} else {
			//printf("rx() failed to get an item within %d ticks\n", TIMEOUT);
		}
	}
}

int main(void) {

	SystemCoreClockUpdate();
	Board_Init();

	setvbuf(stdout, 0, _IONBF, 0);
	setvbuf(stdin, 0, _IONBF, 0);


	queue_handle = xQueueCreate(QUEUESIZE, sizeof(CAN_MSG_T));

	xTaskCreate(tx, (signed char * ) "tx", 1024, NULL, txPrio, NULL);
	xTaskCreate(rx, (signed char * ) "rx", 1024, NULL, rxPrio, NULL);

	vTaskStartScheduler();

	/* Should never arrive here */
	return 1;
}

