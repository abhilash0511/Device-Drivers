#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timers.h"

TaskHandle_t task1,task2;
TimerHandle_t Timer1,Timer2;
void TimerCallback1(TimerHandle_t xTimer1)
{
    printf("Timer1 Fired\n");
}
void TimerCallback2(TimerHandle_t xTimer2)
{
    printf("Timer2 Fired\n");
}
void Task1(void *data)
{
    printf("I'm in Task1\n");
    Timer1 = xTimerCreate("Timer1",pdMS_TO_TICKS(2000),pdTRUE,NULL,TimerCallback1);
    xTimerStart(Timer1,0);
    vTaskDelete(task1);
}
void Task2(void *data)
{
    printf("I'm in Task2\n");
    Timer2= xTimerCreate("Timer2",pdMS_TO_TICKS(2000),pdTRUE,NULL,TimerCallback2);
    xTimerStart(Timer2,0);
    vTaskDelete(task2);
}
void app_main(void)
{
    xTaskCreatePinnedToCore(Task1,"task1",2048,NULL,2,&task1,1);
    xTaskCreatePinnedToCore(Task2,"task2",2048,NULL,4,&task2,1);
}
