//
// Created by 54945 on 2025/10/12.
//

#include "IMU.h"
#include "BMI088.h"


void Acc_calculate(acc_raw_data *data){
    uint8_t rx_acc_data[6], raw_range;
    int16_t acc[3];
    // 1. 设置/读取acc0x41寄存器中的量程range参数，并换算为量程系数
    bmi088_accel_read_reg(0x41, &raw_range, 1);
    // code here

    // 2. 读取acc0x12寄存器中的6位acc数据
    bmi088_accel_read_reg(0x12, rx_acc_data, 6);

    // 3. 用量程系数将原始数据转换为常用单位
    acc[0] = ((int16_t)rx_acc_data[1] << 8) + (int16_t)rx_acc_data[0];
    acc[1] = ((int16_t)rx_acc_data[3] << 8) + (int16_t)rx_acc_data[2];
    acc[2] = ((int16_t)rx_acc_data[5] << 8) + (int16_t)rx_acc_data[4];
    data ->x = (float)acc[0] * BMI088_ACCEL_parm;
    data ->y = (float)acc[1] * BMI088_ACCEL_parm;
    data ->z = (float)acc[2] * BMI088_ACCEL_parm;

    // code here
}

void Gyro_calculate(gyro_raw_data *data){
    uint8_t rx_gyro_data[6],
    // 1. 设置/读取gyro0x0F寄存器中的量程range参数，并换算为量程系数

    // 2. 读取gyro0x02寄存器中的6位gyro数据

    // 3. 用量程系数将原始数据转换为常用单位
}