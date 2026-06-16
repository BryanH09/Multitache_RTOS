#include <Arduino.h>

#define LED_1 12
#define LED_2 13

TaskHandle_t ID_LED_1 = NULL;
TaskHandle_t ID_LED_2 = NULL;

void Thread_LED_1(void *pvParameters)
{

  while(1)
  {
    digitalWrite(LED_1, HIGH);
    vTaskDelay(1000);
    digitalWrite(LED_1, LOW);
    vTaskDelay(1000);
  }
}

void Thread_LED_2(void *pvParameters)
{

  while(1)
  {
    digitalWrite(LED_2, HIGH);
    vTaskDelay(500);
    digitalWrite(LED_2, LOW);
    vTaskDelay(500);
  }
}



void setup() {

  xTaskCreate( Thread_LED_1, "Thread_LED_1", 1000, NULL, 1, &ID_LED_1);
  xTaskCreate( Thread_LED_2, "Thread_LED_2", 1000, NULL, 1, &ID_LED_2);

  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
}

void loop() {

}
