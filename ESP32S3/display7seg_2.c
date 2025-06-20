#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

const uint8_t pins[7] = {4, 5, 6, 7, 8, 9, 10};

const uint8_t nums[10][7] = {
  {1, 1, 1, 1, 1, 1, 0},
  {0, 1, 1, 0, 0, 0, 0},
  {1, 1, 0, 1, 1, 0, 1},
  {1, 1, 1, 1, 0, 0, 1},
  {0, 1, 1, 0, 0, 1, 1},
  {1, 0, 1, 1, 0, 1, 1},
  {1, 0, 1, 1, 1, 1, 1},
  {1, 1, 1, 0, 0, 0, 0},
  {1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 0, 1, 1} 
};

void displayNumber(uint8_t num)
{
    for (uint8_t i = 0; i < 7; i++)
        gpio_set_level((gpio_num_t)pins[i], nums[num][i]);
}

void app_main(void)
{
    for (uint8_t i = 4; i < 11; i++)
        gpio_set_direction((gpio_num_t)i, GPIO_MODE_OUTPUT);
    gpio_set_direction(GPIO_NUM_20, GPIO_MODE_INPUT);
    gpio_set_pull_mode(GPIO_NUM_20, GPIO_PULLUP_ONLY);
    
    uint8_t cont = 0;

    while (1)
    {
        displayNumber(cont);
        if (gpio_get_level(GPIO_NUM_20) == 0)
        {
            vTaskDelay(pdMS_TO_TICKS(200));
            if (gpio_get_level(GPIO_NUM_20) == 0)
                cont == 9 ? cont = 0 : cont++;
        }
        vTaskDelay(pdMS_TO_TICKS(50));
    }
}
