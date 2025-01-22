#include "rbt_lib.h"
Motor::Motor(const uint32_t&& cw, const uint32_t&& ccw)
       :cw(cw), ccw(ccw)
{
       pin_init(cw);
       pin_init(ccw);
}
void stop(const Motor* motor_list){
       for(uint32_t i = 0; i < NUM_MOTORS; i++){
              if(pin_state(motor_list[i].cw)){
                     pin_off(motor_list[i].cw);
              }
              if(pin_state(motor_list[i].ccw)){
                     pin_off(motor_list[i].ccw);
              }
       }
}
void diag_left(const Motor* motor_list){
       pin_off(motor_list[0].ccw);
       pin_on(motor_list[1].ccw);
       pin_off(motor_list[2].cw);
       pin_on(motor_list[3].cw);
}
void diag_right(const Motor* motor_list){
       pin_on(motor_list[0].ccw);
       pin_off(motor_list[1].ccw);
       pin_on(motor_list[2].cw);
       pin_off(motor_list[3].cw);
}
void drift_left(const Motor* motor_list){
       pin_off(motor_list[0].ccw);
       pin_on(motor_list[1].ccw);
       pin_on(motor_list[2].cw);
       pin_on(motor_list[3].cw);
}
void drift_right(const Motor* motor_list){
       pin_on(motor_list[0].ccw);
       pin_on(motor_list[1].ccw);
       pin_on(motor_list[2].cw);
       pin_off(motor_list[3].cw);
}
void move_forward(const Motor* motor_list){
       pin_on(motor_list[0].ccw);
       pin_on(motor_list[1].ccw);
       pin_on(motor_list[2].cw);
       pin_on(motor_list[3].cw);
}
void move_backward(const Motor* motor_list){
       pin_on(motor_list[0].cw);
       pin_on(motor_list[1].cw);
       pin_on(motor_list[2].ccw);
       pin_on(motor_list[3].ccw);
}
void move_left(const Motor* motor_list){
       pin_on(motor_list[0].cw);
       pin_on(motor_list[1].ccw);
       pin_on(motor_list[2].ccw);
       pin_on(motor_list[3].cw);
}
void move_right(const Motor* motor_list){
       pin_on(motor_list[0].ccw);
       pin_on(motor_list[1].cw);
       pin_on(motor_list[2].cw);
       pin_on(motor_list[3].ccw);
}
void spin(const Motor* motor_list){
       pin_on(motor_list[0].cw);
       pin_on(motor_list[1].cw);
       pin_on(motor_list[2].cw);
       pin_on(motor_list[3].cw);
}