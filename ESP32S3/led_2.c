#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{
    gpio_set_direction(GPIO_NUM_5, GPIO_MODE_OUTPUT);
    uint8_t state = 0;
    while (1)
    {
        gpio_set_level(GPIO_NUM_5, state);
        state = !state;
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}
