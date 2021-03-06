#pragma once

#include <sys/time.h>
#include "config.hpp"

class PIDController {

  private:
    double setpoint;
    double KP, KI, KD;
    double err, perr, d_err1, d_err2, pca;
    struct timeval before, after;

  public:
    PIDController(double setpoint, double kp=0.0, double ki=0.0, double kd=0.0);
    PIDController(ControlConfig config);
    double get_ca(double measurement);
    void set_setpoint(double setpoint);
    void update(ControlConfig config);
};
