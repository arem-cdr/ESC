//MAIN DU JOYSTICK

#include <mbed.h>

AnalogIn X(A0);
AnalogIn Y(A1);
PwmOut pwm(D9);
DigitalIn sw(D2);
bool dir = false;

Serial pc(USBTX, USBRX);

int main()
{
  pwm.period_us(2040);
  pwm.pulsewidth_us(2000);
  // put your setup code here, to run once:
  float pulsewidth = 2000;
  int p = 0;
  while (1)
  {
    wait(0.01);
    pulsewidth = X.read();
    if (pulsewidth > 0.4 && pulsewidth < 0.6)
    {
      p = 2000;
      pwm.period_us(2000);
    }
    else if (pulsewidth <= 0.4)
    {
      p = 1060 + (int)(350 - 350.0 * pulsewidth / 0.42);
      pwm.period_us(p);
    }
    else if (pulsewidth >= 0.6)
    {
      p = 1510 + (int)(350 - 350.0 * (1.1 - pulsewidth) / 0.52);
      pwm.period_us(p);
    }

    pc.printf("X : %f | pulse : %d\n", X.read(), p);
    // put your main code here, to run repeatedly:
  }
}