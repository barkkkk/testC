//
// Created by 54945 on 2025/10/12.
//

#include "IMU.h"
#include "BMI088.h"

acc_raw_data imu_acc_data;
gyro_raw_data imu_gyro_data;

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
    uint8_t rx_gyro_data[6], range;
    int16_t gyro[3];
    float unit;
    // 1. 设置/读取gyro0x0F寄存器中的量程range参数，并换算为量程系数
    bmi088_gyro_read_reg(0x7F, &range, 1);
    switch (range) {
        case 0x00:
            unit = 16.384;
            break;
        case 0x01:
            unit = 32.768;
            break;
        case 0x02:
            unit = 65.536;
            break;
        case 0x03:
            unit = 131.072;
            break;
        case 0x04:
            unit = 262.144;
            break;
        default:
            unit = 16.384;
            break;
    }
    // 2. 读取gyro0x02寄存器中的6位gyro数据
    bmi088_gyro_read_reg(0x02, rx_gyro_data, 6);
    gyro[0] = ((int16_t)rx_gyro_data[1] << 8) + (int16_t)rx_gyro_data[0];
    gyro[1] = ((int16_t)rx_gyro_data[3] << 8) + (int16_t)rx_gyro_data[2];
    gyro[2] = ((int16_t)rx_gyro_data[5] << 8) + (int16_t)rx_gyro_data[4];
    // 3. 用量程系数将原始数据转换为常用单位
    data ->roll = (float)gyro[0] / unit * BMI088_GYRO_parm;
    data->pitch = (float)gyro[1] / unit * BMI088_GYRO_parm;
    data -> yaw = (float)gyro[2] / unit * BMI088_GYRO_parm;

}