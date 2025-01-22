#pragma once
#include <iostream>
#include "pico/stdlib.h"
#include "hardware/timer.h"
#include "hardware/gpio.h"
#include "hardware/pwm.h"
#include "hardware/adc.h"
#include "pico/binary_info.h"
#include "hardware/uart.h"

#define NOT_DEFINED 0
#define NUM_MOTORS 4
#define NUM_SENSORS 3
#define NUM_LEDS 3
#define TIMEOUT 200000
#define WRAP 65000
#define OUT 1
#define IN 0
#define ON 1
#define OFF 0
#define LED 25
#define LED_1 NOT_DEFINED
#define LED_2 NOT_DEFINED
#define SWTICH 22
#define SEN_1_SDA 20
#define SEN_1_SCL 21
#define SEN_2_SDA 16
#define SEN_2_SCL 17
#define SEN_3_SDA 18
#define SEN_3_SCL 19
#define MOTOR_1_1 3
#define MOTOR_1_2 28
#define MOTOR_2_1 7
#define MOTOR_2_2 4
#define MOTOR_3_1 10
#define MOTOR_3_2 11
#define MOTOR_4_1 12
#define MOTOR_4_2 13

#define ADC_NUM 0
#define ADC_PIN (23 + ADC_NUM)
#define ADC_VREF 3.3
#define ADC_RANGE (1 << 12)
#define ADC_CONVERT (ADC_VREF / (ADC_RANGE - 1))

using std::cout;
using std::endl;
#define TOGGLE 1
#if TOGGLE
#define log(msg) cout << msg << "\n"
#else 
#define log(msg)
#endif
#define loop(count) for(uint32_t i = 0; i < count; i++)
class Sonic_sensor{
    uint32_t trig_pin; //scl pin
    uint32_t echo_pin; //sda pin
public:
    Sonic_sensor        (const uint32_t&&, const uint32_t&&);
    uint64_t get_inch   (void) const;
    uint64_t get_cm     (void) const;
    uint64_t get_pulse  (void) const;
};
class Motor{
public:
    uint32_t cw, ccw;
    Motor               (const uint32_t&&, const uint32_t&&);
};
void pin_on         (const uint32_t&);
void pin_off        (const uint32_t&);
bool pin_state      (const uint32_t&);
void wait           (const uint32_t&);
void pin_init       (const uint32_t&, const uint32_t& = OUT);
void logic          (const Sonic_sensor*, const Motor*, uint32_t&);
void logic2         (const Sonic_sensor*, const Motor*, uint32_t&);
void stop           (const Motor*);
void diag_left      (const Motor*);
void diag_right     (const Motor*);
void drift_left     (const Motor*);
void drift_right    (const Motor*);
void move_forward   (const Motor*);
void move_backward  (const Motor*);
void move_right     (const Motor*);
void move_left      (const Motor*);
void spin           (const Motor*);