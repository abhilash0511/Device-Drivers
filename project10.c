#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timers.h" 
TimerHandle_t myTimer;  
TaskHandle_t TASK1;
void vCallbackFunction(TimerHandle_t kolli)
{
    int a = 45, b = 18;
    int c = a + b;
    printf("THE SUM OF %d and %d is %d\n", a, b, c);
}
void task1(void *pvParameters)
{
    printf("I AM IN TASK1\n");

    myTimer=xTimerCreate("sai", pdMS_TO_TICKS(5000), pdFALSE, NULL, vCallbackFunction);
    xTimerStart(myTimer,0);
    vTaskDelete(NULL); 
}
void app_main(void)
{
    xTaskCreatePinnedToCore(task1, "task1", 2048, NULL, 9, &TASK1, 1);
}