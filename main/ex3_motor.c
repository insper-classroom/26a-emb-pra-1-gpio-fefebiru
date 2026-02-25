/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int FASE_PIN_4 = 9;
const int FASE_PIN_3 = 8;
const int FASE_PIN_2 = 7;
const int FASE_PIN_1 = 6;
const int LED_PIN = 5;

const int BTN_PIN = 28;

int main() {
  stdio_init_all();

  gpio_init(LED_PIN);
  gpio_set_dir(LED_PIN, GPIO_OUT);

  gpio_init(FASE_PIN_1);
  gpio_set_dir(FASE_PIN_1, GPIO_OUT);

  gpio_init(FASE_PIN_2);
  gpio_set_dir(FASE_PIN_2, GPIO_OUT);

  gpio_init(FASE_PIN_3);
  gpio_set_dir(FASE_PIN_3, GPIO_OUT);

  gpio_init(FASE_PIN_4);
  gpio_set_dir(FASE_PIN_4, GPIO_OUT);

  gpio_init(BTN_PIN);
  gpio_set_dir(BTN_PIN, GPIO_IN);
  gpio_pull_up(BTN_PIN);

  while (true) {
    // Use delay de 300 ms entre os estados!

      if (!gpio_get(BTN_PIN)) {

        gpio_put(LED_PIN, 1);
        sleep_ms(250);

        gpio_put(LED_PIN, 0);
        sleep_ms(250);

        for (int i=0; i<=512;i++){
            gpio_put(FASE_PIN_1, 1);
            gpio_put(FASE_PIN_2, 0);
            gpio_put(FASE_PIN_3, 0);
            gpio_put(FASE_PIN_4, 0);
            sleep_ms(10);
    
            gpio_put(FASE_PIN_1, 0);
            gpio_put(FASE_PIN_2, 1);
            gpio_put(FASE_PIN_3, 0);
            gpio_put(FASE_PIN_4, 0);
            sleep_ms(10);
    
            gpio_put(FASE_PIN_1, 0);
            gpio_put(FASE_PIN_2, 0);
            gpio_put(FASE_PIN_3, 1);
            gpio_put(FASE_PIN_4, 0);
            sleep_ms(10);
    
            gpio_put(FASE_PIN_1, 0);
            gpio_put(FASE_PIN_2, 0);
            gpio_put(FASE_PIN_3, 0);
            gpio_put(FASE_PIN_4, 1);
            sleep_ms(10);
        }
        gpio_put(FASE_PIN_1, 0);
        gpio_put(FASE_PIN_2, 0);
        gpio_put(FASE_PIN_3, 0);
        gpio_put(FASE_PIN_4, 0);
        while (!gpio_get(BTN_PIN)) {
      };
      }
  }
}