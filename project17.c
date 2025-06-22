#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <string.h>
#include"freertos/queue.h"


TaskHandle_t task1_h,task2_h,task3_h;
QueueHandle_t queue_h;



void task1(void *data)
{
    char buff[20]="abhiveeraimranmani\n";
    printf("from task 1-I'm sending the data\n");
    xQueueSend(queue_h, buff, portMAX_DELAY );
    printf("I SENT DAta %s\n",buff);
    vTaskDelete(task1_h);
}


void task2(void *data)
{
    int a=45;
    printf("From task 2-I'm sending the data\n");
    xQueueSend(queue_h, &a, portMAX_DELAY);
    printf("I SENT DAta\n");
    vTaskDelete(task2_h);
}

void task3(void *data)
{
    int a;
    char r_buff[15];
    printf("waiting to receive data\n");
    vTaskDelay(pdMS_TO_TICKS(3000));
    xQueueReceive( queue_h, &a, portMAX_DELAY);
    printf("The integer received is :%d\n",a);
    vTaskDelay(pdMS_TO_TICKS(3000));
    xQueueReceive( queue_h, r_buff, portMAX_DELAY );
    printf("The string received is :%s\n",r_buff);
    vTaskDelete(task3_h);
}


void app_main(void)
{
    queue_h=xQueueCreate(3,20);

    xTaskCreatePinnedToCore( task1,"task1",2048,NULL,2,&task1_h,1);
    xTaskCreatePinnedToCore( task2,"task2",2048,NULL,4,&task2_h,1);    
    xTaskCreatePinnedToCore( task3,"task3",2048,NULL,1,&task3_h,1);
                                         
}