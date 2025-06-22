#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

TaskHandle_t Task1,Task2,Task3;

void task1(void *data)
{
    while (1)
    {
         printf("I AM IN TASK1\n");
         vTaskDelay(pdMS_TO_TICKS(2000));
         vTaskResume(Task2);
         vTaskResume(Task3);
    }
    vTaskDelete(Task1);
}

void task2(void *data)
{
    while (1)
    {
        vTaskSuspend(Task2);
        printf("I AM IN TASK2\n");
    }
    vTaskDelete(Task2);
}
void task3(void *data)
{
    while (1)
    {
        vTaskSuspend(Task3);
        printf("I AM IN TASK3\n");
    }
    vTaskDelete(Task3);
}
void app_main(void)
{
     xTaskCreatePinnedToCore(task1,"task1",2048,NULL,7,&Task1,1);
     xTaskCreatePinnedToCore(task2,"task2",2048,NULL,9,&Task2,1);
     xTaskCreatePinnedToCore(task3,"task3",2048,NULL,10,&Task3,1);
}
