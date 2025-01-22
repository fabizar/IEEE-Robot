#include "rbt_lib.h"

int main() {
    log("start");
    stdio_init_all();
    pin_init(LED);
    Sonic_sensor sensor1(SEN_1_SCL, SEN_1_SDA);
    Sonic_sensor sensor2(SEN_2_SCL, SEN_2_SDA);
    Sonic_sensor sensor3(SEN_3_SCL, SEN_3_SDA);
    Sonic_sensor sensor_list[NUM_SENSORS] = {sensor1, sensor2, sensor3};
    Motor motor1(MOTOR_1_1, MOTOR_1_2);
    Motor motor2(MOTOR_2_1, MOTOR_2_2);
    Motor motor3(MOTOR_3_1, MOTOR_3_2);
    Motor motor4(MOTOR_4_1, MOTOR_4_2);
    Motor motor_list[NUM_MOTORS] = {motor1, motor2, motor3, motor4};
    int i = 0;
    uint32_t state = 1;
    wait(1000);
    while(1) {
        pin_on(LED);
        logic(sensor_list, motor_list, state);
        wait(100);
        i++;
        log("tick.... " << i << '\n');
        pin_off(LED);
        wait(100);
    }
    return 0;
}