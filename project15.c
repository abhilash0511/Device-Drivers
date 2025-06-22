#include <stdio.h>
#include"freertos/FreeRTOS.h"
#include"freertos/task.h"
#include"freertos/semphr.h"

TaskHandle_t task1_h,task2_h,task3_h,task4_h,task5_h,task6_h;

SemaphoreHandle_t sem_handle;

void task1(void *data)
{
    printf("serial port 1 is waiting!\n");
    xSemaphoreTake( sem_handle,portMAX_DELAY);
    printf("LOCK ACQUIRED by SERIAL PORT 1\n");
    vTaskDelay(pdMS_TO_TICKS(3000));
    xSemaphoreGive( sem_handle);
    vTaskDelete(task1_h);
}

void task2(void *data)
{
    printf("serial port 2 is waiting!\n");
    xSemaphoreTake( sem_handle,portMAX_DELAY);
    printf("LOCK ACQUIRED by SERIAL PORT 2\n");
    vTaskDelay(pdMS_TO_TICKS(3000));
    xSemaphoreGive( sem_handle);
    vTaskDelete(task2_h);
}

void task1(void *data)
{
    printf("serial port 3 is waiting!\n");
    xSemaphoreTake( sem_handle,portMAX_DELAY);
    printf("LOCK ACQUIRED by SERIAL PORT 3\n");
    vTaskDelay(pdMS_TO_TICKS(3000));
    xSemaphoreGive( sem_handle);
    vTaskDelete(task3_h);
}

void task1(void *data)
{
    printf("serial port 4 is waiting!\n");
    xSemaphoreTake( sem_handle,portMAX_DELAY);
    printf("LOCK ACQUIRED by SERIAL PORT 4\n");
    vTaskDelay(pdMS_TO_TICKS(3000));
    xSemaphoreGive( sem_handle);
    vTaskDelete(task4_h);
}

void task1(void *data)
{
    printf("serial port 5 is waiting!\n");
    xSemaphoreTake( sem_handle,portMAX_DELAY);
    printf("LOCK ACQUIRED by SERIAL PORT 5\n");
    vTaskDelay(pdMS_TO_TICKS(3000));
    xSemaphoreGive( sem_handle);
    vTaskDelete(task5_h);
}

void task1(void *data)
{
    printf("serial port 6 is waiting!\n");
    xSemaphoreTake( sem_handle,portMAX_DELAY);
    printf("LOCK ACQUIRED by SERIAL PORT 6\n");
    vTaskDelay(pdMS_TO_TICKS(3000));
    xSemaphoreGive( sem_handle);
    vTaskDelete(task6_h);
}



void app_main(void)
{
    sem_handle = xSemaphoreCreateCounting(2,2);

    xTaskCreatePinnedToCore( task1,"task1",2048,NULL,1,&task1_h,1);
    xTaskCreatePinnedToCore( task2,"task2",2048,NULL,2,&task2_h,1);
    xTaskCreatePinnedToCore( task3,"task3",2048,NULL,3,&task3_h,1);
    xTaskCreatePinnedToCore( task4,"task4",2048,NULL,4,&task4_h,1);
    xTaskCreatePinnedToCore( task5,"task5",2048,NULL,5,&task5_h,1);
    xTaskCreatePinnedToCore( task6,"task6",2048,NULL,6,&task6_h,1);


}
