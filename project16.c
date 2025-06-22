#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/message_buffer.h"
#include <string.h>
TaskHandle_t task1_h,task2_h;
MessageBufferHandle_t buffer_h;
void task1(void *data)
{
   printf("I AM SENDING THE DATA TO TASK 2\n");
   xMessageBufferSend( buffer_h,"abhi",strlen("abhi"),portMAX_DELAY);
   xMessageBufferSend( buffer_h,"veera",strlen("veera"),portMAX_DELAY);

   vTaskDelay(pdMS_TO_TICKS(2000));
   printf("I SENT DATA TO TASK 2\n");
   vTaskDelete(task1_h);
}

void task2(void *data)
{
   char buff[10];
   printf("I AM READY TO RECIEVE DATA FROM TASK 1\n");
   xMessageBufferReceive( buffer_h,buff,5,portMAX_DELAY);
   printf("I RECIEVED DATA %s\n",buff);
   xMessageBufferReceive( buffer_h,buff,6,portMAX_DELAY);
   printf("I RECIEVED DATA %s\n",buff);
   vTaskDelete(task2_h);
}

void app_main(void)
{
    buffer_h= xMessageBufferCreate(100);
    xTaskCreatePinnedToCore( task1,"task1",2048,NULL,2,&task1_h,1);
    xTaskCreatePinnedToCore( task2,"task2",2048,NULL,1,&task2_h,1);                                             
}
