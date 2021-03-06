/*
* Ryan Lee
* IGEN 430 Capstone Project
* Header file containing calibrator class and modules based on https://github.com/Protonerd/DIYino/blob/master/MPU6050_calibration.ino
*/
#include <Arduino.h>
#include <MPU6050.h>
#include <I2Cdev.h>
#include "Wire.h"

#define N_DATA                  6
#define MAX_CAL_LOOPS           20
#define PREF_MAX_CAL_LOOPS      6
#define PREF_BUFF_SIZE          100
#define BUFF_SIZE               500
#define OFFSET_DEADZONE         6

class Calibrator
{
    public:
        int axo=0,ayo=0,azo=0,gxo=0,gyo=0,gzo=0;
        bool calibration(MPU6050 accelgyro, int16_t offsets[N_DATA],byte max_loops, int buffersize);
    private:
        //config
        int num_meas_to_discard = 100; //num inital measurements to discard
        int acel_deadzone       = 3; //accelerometer error allowed, lower value means higher precision
        int gyro_deadzone       = 3; //gyro error allowed, lwoer value means higher precision
        int acel_offset_div     = 6; //taken from src code
        int gyro_offset_div     = 4; //taken from src code
        //deadzone -- amount of variation between 2 consecutive measurements
        void calculate_mean(MPU6050 accelgyro, int16_t means[N_DATA], int buffersize);
};
