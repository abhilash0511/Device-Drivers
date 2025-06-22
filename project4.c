#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
TaskHandle_t Task1;
TaskHandle_t Task2;
int a=10;
char str[]="Veera Sai";
void task1(void *data)
{
    int d= *(int *)data;
    while (1)
    {
        printf("I AM IN TASK1\n");
        printf("D value is %d\n",d);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
     vTaskDelete(Task1);
    
}
void task2(void *data)
{
   char *e= (char *)data;
    while (1)
    {
        printf("I AM IN TASK2\n");
        printf("E value is %s\n",e);
        vTaskDelay( pdMS_TO_TICKS(1000));
    }
     vTaskDelete(Task2);
    }
    void app_main(void)
    {
    xTaskCreatePinnedToCore( task1,"NAME1",2048,&a,3,&Task1,1);
    xTaskCreatePinnedToCore( task2,"NAME2",2048,str,7,&Task2,1);
}
