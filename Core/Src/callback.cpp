//
// Created by 54945 on 2025/10/12.
//

#include "../Inc/callback.h"

#include "tim.h"
#include "IMU.h"
#include "BMI088.h"


void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim) {
    if (htim->Instance == htim6.Instance){
        //HAL_CAN_AddTxMessage(&hcan1,&tx_header,tx_data,&transmit_box);
    }
}
