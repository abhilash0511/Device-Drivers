#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
TaskHandle_t Task1;
TaskHandle_t Task2;
void task1(void *data)
{
    while (1)
    {
        printf("I AM IN TASK1\n");
        vTaskDelay( 1000/ portTICK_PERIOD_MS);
    }
     vTaskDelete( Task1 );
    
}
void task2(void *data)
{
    while (1)
    {
        printf("I AM IN TASK2\n");
        vTaskDelay( 1000/ portTICK_PERIOD_MS);
    }
     vTaskDelete( Task2 );
}
void app_main(void)
{
    xTaskCreatePinnedToCore( task1,"NAME1",2048,NULL,3,&Task1,1);
    xTaskCreatePinnedToCore( task2,"NAME2",2048,NULL,7,&Task2,1);
}
