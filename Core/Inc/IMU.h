//
// Created by 54945 on 2025/10/12.
//

#ifndef CSPI_IMU_H
#define CSPI_IMU_H


class IMU {
};


typedef struct acc_raw_data {
    float x;
    float y;
    float z;
} acc_raw_data;

typedef struct gyro_raw_data {
    float roll;
    float pitch;
    float yaw;
} gyro_raw_data;

//换算函数
void Acc_calculate(acc_raw_data *data);
void Gyro_calculate(gyro_raw_data *data);

#endif //CSPI_IMU_H