#include "rbt_lib.h" 
void pin_init(const uint32_t& pin, const uint32_t& dir){
    gpio_init(pin);
    gpio_set_dir(pin, dir);
}
void pin_on(const uint32_t& pin){
    gpio_put(pin, ON);
}
void pin_off(const uint32_t& pin){
    gpio_put(pin, OFF);
}
void wait(const uint32_t& time){
    sleep_ms(time);
}
bool pin_state(const uint32_t& pin){
    return gpio_get(pin);
}