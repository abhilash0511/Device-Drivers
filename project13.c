#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timers.h"

TaskHandle_t task1,task2;
TimerHandle_t Timer1;
void TimerCallback1(TimerHandle_t xTimer1)
{
    printf("Timer1 Fired\n");
    vTaskResume(task1);
}

void Task1(void *data)
{
    while(1)
    {
        vTaskSuspend(task1); 
        printf("I'm in Task1\n");
        vTaskDelay(pdMS_TO_TICKS(3000));
        vTaskResume(task2);
    }
    vTaskDelete(task1);
}
void Task2(void *data)
{
    while(1)
    {
        vTaskSuspend(task2); 
        printf("I'm in Task2\n");
        vTaskDelay(pdMS_TO_TICKS(3000));
        vTaskResume(task1);
    }
}
void app_main(void)
{
    Timer1 = xTimerCreate("Timer1",pdMS_TO_TICKS(2000),pdFALSE,NULL,TimerCallback1);
    
    xTaskCreatePinnedToCore(Task1,"task1",2048,NULL,2,&task1,1);
    xTaskCreatePinnedToCore(Task2,"task2",2048,NULL,4,&task2,1);
    
    xTimerStart(Timer1,0);

    
}
