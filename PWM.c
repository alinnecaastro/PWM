#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pwm.h"

#define PWM_PIN 22 // GPIO 22


int main() {
    // Configuração do PWM no RP2040
    gpio_set_function(PWM_PIN, GPIO_FUNC_PWM); // Configura o pino para função PWM

    // Obtém o slice e o canal do PWM para o pino
    uint slice_num = pwm_gpio_to_slice_num(PWM_PIN);
    uint channel_num = pwm_gpio_to_channel(PWM_PIN);

    // Configura a frequência do PWM para 50 Hz (período de 20 ms)
    pwm_set_clkdiv(slice_num, 125.0f); // Divisor de clock (125 MHz / 125 = 1 MHz)
    pwm_set_wrap(slice_num, 20000);    // Wrap value para 20 ms (1 MHz / 20000 = 50 Hz)

    // Habilita o PWM
    pwm_set_enabled(slice_num, true);

    

    // 1) Define o ciclo ativo para 2.400 µs (180 graus)
    pwm_set_chan_level(slice_num, channel_num, 2400);
   
    sleep_ms(5000); // Aguarda 5 segundos

    // 2) Define o ciclo ativo para 1.470 µs (90 graus)
    pwm_set_chan_level(slice_num, channel_num, 1470);
    
    sleep_ms(5000); // Aguarda 5 segundos

    // 3) Define o ciclo ativo para 500 µs (0 graus)
    pwm_set_chan_level(slice_num, channel_num, 500);
    
    sleep_ms(5000); // Aguarda 5 segundos

    // 4) Movimentação periódica entre 0 e 180 graus
    while (true) {
        // Move de 0 a 180 graus
        for (int pulse_width = 500; pulse_width <= 2400; pulse_width += 5) {
            pwm_set_chan_level(slice_num, channel_num, pulse_width);
            sleep_ms(10); // Aguarda 10 ms para movimento suave
        }

        // Move de 180 a 0 graus
        for (int pulse_width = 2400; pulse_width >= 500; pulse_width -= 5) {
            pwm_set_chan_level(slice_num, channel_num, pulse_width);       
            sleep_ms(10); // Aguarda 10 ms para movimento suave
        }
    }

    return 0;
}