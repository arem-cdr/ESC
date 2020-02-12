#include <mbed.h>

// TO DO
// Rajouter un getSpeed sur la vitesse des moteurs

#define TON_MIN 1060
#define TON_MAX 1860
#define TON_MIN_HALF 1410
#define TON_MAX_HALF 1510

class ESC
{
public:
    ESC(PinName pinG, PinName pinD);
    void Set_Speed_G(int s, int d);
    void Set_Speed_D(int s, int d);
    void Stop_G();
    void Stop_D();
    void Stop_All();
    ~ESC();

private:
    PwmOut *speedG_pwm;
    PwmOut *speedD_pwm;
};