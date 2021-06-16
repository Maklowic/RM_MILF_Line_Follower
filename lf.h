#ifndef LINEFOLLOWER_H
#define LINEFOLLOWER_H

void PWM(int left, int right);
void SenSelect()
void managedir()
int calc_err();
int PD_reg();
void LF_loop();
void AllForth();
int None();
int isBlack(int x);
void SetSpeed(int speed, char dir);
void Control(int Dir, char moto);

#endif
