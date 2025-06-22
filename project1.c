#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
TaskHandle_t abhi;
TaskHandle_t abhi1;
TaskHandle_t abhi2;
void myfunction(void *data)
{
    printf("I am in my function\n");
     vTaskDelete(abhi);

}
void myfunction1(void *data)
{
    printf("I am in my function1\n");
     vTaskDelete(abhi1);
}
void myfunction2(void *data)
{
    printf("I am in my function2\n");
     vTaskDelete(abhi2);
}
void app_main(void)
{
    BaseType_t xReturned;
	printf("I am in main function\n");
	xReturned=xTaskCreate( myfunction,"Name",2048,NULL,3,&abhi);
        if(xReturned == pdPASS)
       {
        	printf("myfunction is created\n");
       }
	xReturned=xTaskCreate( myfunction1,"Name1",2048,NULL,2,&abhi1);
	  if(xReturned == pdPASS)
       {
        	printf("myfunction1 is created\n");
       }
	xReturned=xTaskCreate( myfunction2,"Name2",2048,NULL,1,&abhi2);
	  if(xReturned == pdPASS)
       {
        	printf("myfunction2 is created\n");
       }

}
