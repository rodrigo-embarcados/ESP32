#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{
    gpio_set_direction(GPIO_NUM_5, GPIO_MODE_OUTPUT);

    while (1)
    {
        gpio_set_level(GPIO_NUM_5, 1);
        vTaskDelay(pdMS_TO_TICKS(500));
        gpio_set_level(GPIO_NUM_5, 0);
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}
