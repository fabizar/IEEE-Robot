#include "rbt_lib.h" 
void logic(const Sonic_sensor* sensor_list, const Motor* motor_list, uint32_t& state){
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

    //go forward
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
    //strafe left
    if(state == 2){
        log("state 2");
        if(s2 > 10 || s3 > 10){
            state = 3;
            stop(motor_list);
            wait(100);
        }
        else{
            move_left(motor_list);
        }
    }
    //press button
    if(state == 3){
        log("in 3");
        if(s1 < 6){
            log("button press");
            state = 4;
            stop(motor_list);
            wait(100);
        }
        else{
            move_forward(motor_list);
        }
    }
    //back off button
    if(state == 4){
            log("in 4");
        if(s1 > 12){
            state = 5;
            stop(motor_list);
            wait(100);
        }
        else{
            move_backward(motor_list);
        }
    }
    //strafe left
    if(state == 5){
            log("in 5");
        if(s2 > 30 || s3 > 30){
            state = 6;
            stop(motor_list);
            wait(100);
        }
        else{
            move_left(motor_list);
        }
    }
    //spin
    if(state == 6){
        log("in 6");
        if(s1 > 800){
            state = 7;
            stop(motor_list);
            wait(100);
        }
        else{
            spin(motor_list);
        }
    }
        if(state == 7){
        if(s1 < front_wall){
            log("stop");
            stop(motor_list);
            state = 8;
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
        if(state == 8){
        log("state 2");
        if(s2 > 10 || s3 > 10){
            state = 9;
            stop(motor_list);
            wait(100);
        }
        else{
            move_left(motor_list);
        }
    }
        //press button
    if(state == 9){
        log("in 3");
        if(s1 < 6){
            log("button press");
            state = 10;
            stop(motor_list);
            wait(100);
        }
        else{
            move_forward(motor_list);
        }
    }
    //back off button
    if(state == 10){
        stop(motor_list);
    }
}