#include "senderTask.h"
#include <stdio.h>
#include <math.h> // for NAN

extern QueueHandle_t q;

void senderTask(void* argument) {
	float msg = 1.0f;
	TickType_t wakeTime = xTaskGetTickCount();
	TickType_t period = pdMS_TO_TICKS(50U); // periodo di 50ms

	// some fpu related tests, don't mind
	#ifdef configENABLE_FPU
	printf("HELLO MOTHERFUCKER\n");
	#endif

	#if configENABLE_FPU
	printf("OH NO MOTHERFUCKER\n");
	#endif

	// proviamo a mandare dei nan e poi si inizia a mandare valori non nan 
	for(size_t j = 0; j<5; ++j) {
		vTaskDelayUntil(&wakeTime, period);
		msg = NAN;
		xQueueSend(q, &msg, 0U);
	}

	// make it defined again
	msg = 1.0f;

	while(1) {
		vTaskDelayUntil(&wakeTime, period);
		msg = (float) ((int)(msg + 1) %20) + 0.5;
		xQueueSend(q, &msg, 0U);
	}
}
