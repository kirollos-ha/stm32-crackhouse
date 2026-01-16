#include "receiverTask.h"
#include <stdio.h>

extern QueueHandle_t q;

void receiverTask(void* argument) {
	int a = 0;
	float msg;
	while(1) {
		// xQueueReceive(q, (void*)&msg, portMAX_DELAY);
		xQueueReceive(q, &msg, portMAX_DELAY);
		printf("ho ricevuto un %f\n", msg);
		printf("ai fini di non avere int a optimized out, %d\n", a);
	}
}
