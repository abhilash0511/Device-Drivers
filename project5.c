#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
TaskHandle_t t1,t2;
void task1(void *data)
{
    while (1)
    {
       UBaseType_t p1= uxTaskPriorityGet(t1);
       printf("I am in Task1 with priority %d\n",p1);
        vTaskDelay( pdMS_TO_TICKS(1000));
    }
    
}
void task2(void *data)
{
    while (1)
    {
       UBaseType_t p2= uxTaskPriorityGet(t2);
       printf("I am in Task2 with priority %d\n",p2);
       vTaskDelay( pdMS_TO_TICKS(1000));
    }
    
}
void app_main(void)
{
        xTaskCreatePinnedToCore(task1,"task1",2048,NULL,4,&t1,1);
        xTaskCreatePinnedToCore(task2,"task2",2048,NULL,8,&t2,1);
}
