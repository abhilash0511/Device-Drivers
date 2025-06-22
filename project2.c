#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
TaskHandle_t task1;
TaskHandle_t task2;
void Task1(void *data)
{
    printf("I AM IN TASK1\n");
    vTaskDelete(task1);
}
void Task2(void *data)
{
    printf("I AM IN TASK2\n");
    vTaskDelete(task2);
}
void app_main(void)
{
    printf("I am in Main\n");
    xTaskCreatePinnedToCore(Task1,"NAME",2048,NULL,2,&task1,1);
    
    xTaskCreatePinnedToCore(Task2,"NAME1",2048,NULL,3,&task2,1);
}