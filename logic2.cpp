#include "rbt_lib.h"
void logic2(const Sonic_sensor* sensor_list, Motor* motor_list, uint32_t& state){
    uint64_t sensor[NUM_SENSORS] = {};
    for(uint32_t i = 0; i < NUM_SENSORS; i++){
        sensor[i] = sensor_list[i].get_cm();
        log("distance: " << i + 1 << " -> " << sensor[i]);
    }
    uint32_t s1 = sensor[0];
    uint32_t s2 = sensor[1];
    uint32_t s3 = sensor[2];
    int32_t s_error = s2 - s3;
    uint32_t front_wall = 12;
    uint32_t min_side_wall = 3;
    uint32_t max_side_wall = 5;

    if(state == 1){
        if(s1 < front_wall){
            log("stop");
            stop(motor_list);
            state = 2;
            wait(100);
        }
        else if(s2 > max_side_wall && s3 > max_side_wall){
            log("diag right");
            diag_right(motor_list);
        }
        else if(s2 < min_side_wall || s3 < min_side_wall){
            log("diag left");
            diag_left(motor_list);
        }
        else if(s_error < -1){
            log("drift left");
            drift_left(motor_list);
        }
        else if(s_error > 1){
            log("drift right");
            drift_right(motor_list);
        }
        else{
            log("move forward" );
            move_forward(motor_list);
        }
    }
    if(state == 2){
        log("in 6");
        if(s1 > 800){
            state = 1;
            stop(motor_list);
            wait(100);
        }
        else{
            spin(motor_list);
        }
    }
}