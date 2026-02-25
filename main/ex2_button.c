/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

static const int LED_PIN = 5;

static const int BTN_PIN = 28;


int main(void) {
    stdio_init_all();

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_init(BTN_PIN);
    gpio_set_dir(BTN_PIN, GPIO_IN);
    gpio_pull_up(BTN_PIN);


    int led = 0;

    int last = 1; // pull-up => solto = 1


    while (true) {
        int cur = gpio_get(BTN_PIN);

        // Detecta borda de descida: 1 -> 0 (apertou)
        if (last && !cur) {
            led = !led;
            gpio_put(LED_PIN, led);
        }

        last = cur;

    }
}