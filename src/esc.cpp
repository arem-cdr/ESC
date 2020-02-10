#include "esc.h"

ESC::ESC(PinName pinG, PinName pinD)
{
    speedG_pwm = new PwmOut(pinG);
    speedD_pwm = new PwmOut(pinD);
    speedG_pwm->period_us(2040);
    speedD_pwm->period_us(2040);
}

ESC::~ESC()
{
    delete (speedG_pwm);
    delete (speedD_pwm);
}

void ESC::Set_Speed_G(int s, int d) //0 et 350
{
    int p = 2000;
    if (d == 0)
    {
        p = TON_MIN + s;
    }
    else
    {
        p = TON_MAX_HALF + s;
    }
    speedG_pwm->pulsewidth_us(p);
}
void ESC::Set_Speed_D(int s, int d)
{
    int p = 2000;
    if (d == 0)
    {
        p = TON_MIN + s;
    }
    else
    {
        p = TON_MAX_HALF + s;
    }
    speedG_pwm->pulsewidth_us(p);
}

void ESC::Stop_G()
{
    speedG_pwm->pulsewidth_us(2000);
}

void ESC::Stop_D()
{
    speedD_pwm->pulsewidth_us(2000);
}