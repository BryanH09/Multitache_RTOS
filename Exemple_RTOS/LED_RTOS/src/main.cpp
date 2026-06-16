/**
 * @file main.cpp
 * @brief Allume/eteint deux LEDS en multitâche avec FreeRTOS sur ESP32
 * 
 * @note Ce programme permet de visualiser la base même de l'utilisation des multitâches
 * @see Lien utile : http://tvaira.free.fr/esp32/esp32-freertos.html
 * @author Bryan
 * @date 16/06/2026
 */

#include <Arduino.h>

#define LED_1 12    // Attributions des numéros broches GPIO pour les LEDS
#define LED_2 13

/*--- Identifiants des tâches ---*/

TaskHandle_t ID_LED_1 = NULL;
TaskHandle_t ID_LED_2 = NULL;

/**
 * @fn void Thread_LED_1(void *pvParameters)
 * @brief Allume/éteint la LED 1 toutes les 1000 ms
 * @note Priorité 1
 * @param pvParameters Paramètres de la tâche (non utilisés ici)
 * @return void
 */

void Thread_LED_1(void *pvParameters)
{
  while(1)
  {
    digitalWrite(LED_1, HIGH);
    vTaskDelay( pdMS_TO_TICKS(1000));
    digitalWrite(LED_1, LOW);
    vTaskDelay( pdMS_TO_TICKS(1000));
  }
}

/**
 * @fn void Thread_LED_2(void *pvParameters)
 * @brief Allume/éteint la LED 2 toutes les 500 ms
 * @note Priorité 1
 * @param pvParameters Paramètres de la tâche (non utilisés ici)
 * @return void
 */

void Thread_LED_2(void *pvParameters)
{

  while(1)
  {
    digitalWrite(LED_2, HIGH);
    vTaskDelay( pdMS_TO_TICKS(500));
    digitalWrite(LED_2, LOW);
    vTaskDelay( pdMS_TO_TICKS(500));
  }
}


void setup() {

  /*--- Configurations des tâches (threads) ---*/
  
  // Nom de la fonction du thread, "nom du thread", taille de la pile, paramètres si besoin, priorité, identifiant du thread
  xTaskCreate( Thread_LED_1, "Thread_LED_1", 1000, NULL, 1, &ID_LED_1); 
  xTaskCreate( Thread_LED_2, "Thread_LED_2", 1000, NULL, 1, &ID_LED_2); 

  pinMode(LED_1, OUTPUT);   // Configuration des LEDS en sortie
  pinMode(LED_2, OUTPUT);
}

void loop() {
  // Rien car on fonctionne en multitâche !
}
