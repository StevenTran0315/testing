#ifndef DriveWithJoystick_H
#define DriveWithJoystick_H

#include "RobotMap.h"
#include "Robot.h"
#include "frc/WPILib.h"

class DriveWithJoystick : public frc::Command {
public:
    DriveWithJoystick();
    void Initialize()override;
    void Execute()override;
    bool IsFinished()override;
    void End()override;
    void Interrupted()override;
};

#endif // DriveWithJoystick_H