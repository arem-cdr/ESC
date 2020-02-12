//MAIN DU JOYSTICK

#include <mbed.h>
#include "esc.h"

AnalogIn X(A0);
AnalogIn Y(A1);
ESC esc(D14, D9);

int main()
{
  esc.Stop_All();
  wait(3);
  esc.Set_Speed_G(100, 0);
  esc.Set_Speed_D(100, 0);
  wait(0.5);
  esc.Set_Speed_G(150, 0);
  esc.Set_Speed_D(150, 0);
  wait(0.5);
  esc.Set_Speed_G(200, 0);
  esc.Set_Speed_D(200, 0);
  wait(0.5);
  esc.Set_Speed_G(250, 0);
  esc.Set_Speed_D(250, 0);
  wait(0.5);
  esc.Set_Speed_G(300, 0);
  esc.Set_Speed_D(300, 0);
  wait(0.5);
  esc.Set_Speed_G(350, 0);
  esc.Set_Speed_D(350, 0);
  wait(0.5);
  esc.Stop_All();
  wait(1);
  esc.Set_Speed_G(100, 0);
  esc.Set_Speed_D(100, 1);
  wait(5);
  esc.Stop_All();

  return 0;
}