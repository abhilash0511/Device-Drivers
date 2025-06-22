#include <stdio.h>
#include"freertos/FreeRTOS.h"
#include"freertos/task.h"
#include"freertos/semphr.h"

TaskHandle_t task1_h,task2_h;

SemaphoreHandle_t sem_handle;

void task1(void *data)
{
    printf("I'm waiting for the semaphore\n");
    xSemaphoreTake(sem_handle,portMAX_DELAY);
    printf("LOCK ACQUIRED\n");
    printf("I'm in task 1 \n");
    vTaskDelete(task1_h);
}

void task2(void *data)
{

    printf("I'm in task 2 \n");
    vTaskDelay(pdMS_TO_TICKS(3000));
    xSemaphoreGive( sem_handle );
    printf("semphore is given to task1\n");
    vTaskDelete(task2_h);

}

void app_main(void)
{
    sem_handle=xSemaphoreCreateBinary();
    xTaskCreatePinnedToCore( task1,"task1",2048,NULL,1,&task1_h,1);
    xTaskCreatePinnedToCore( task2,"task2",2048,NULL,2,&task2_h,1);
}
