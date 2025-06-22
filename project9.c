#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

TaskHandle_t Task1;
TaskHandle_t Task2;

struct student
{
    int id;
    char name[20];
};
struct student s1={16,"VeeraSai"};
struct student s2={28,"Imran"};
void task1(void *data)
{
   struct student *rec = (struct student *)data;
    while (1)
    {
        printf("I AM IN TASK1\n");
        printf("1. ID value is %d and Name is %s\n",rec->id,rec->name);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
     vTaskDelete(Task1);
    
}
void task2(void *data)
{
    struct student *rec = (struct student *)data;
    while (1)
    {
        printf("I AM IN TASK2\n");
        printf("2. ID value is %d and Name is %s\n",rec->id,rec->name);
        vTaskDelay( pdMS_TO_TICKS(1000));
    }
    vTaskDelete(Task2);
}
void app_main(void)
{

    xTaskCreatePinnedToCore( task1,"NAME1",2048,&s1,3,&Task1,1);
    xTaskCreatePinnedToCore( task2,"NAME2",2048,&s2,7,&Task2,1);
}