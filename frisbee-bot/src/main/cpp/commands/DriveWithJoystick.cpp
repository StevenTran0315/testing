#include "../include/commands/DriveWithJoystick.h"

DriveWithJoystick::DriveWithJoystick() {
    Requires(Robot::drivetrain.get());
}

void DriveWithJoystick::Initialize() {

}

void DriveWithJoystick::Execute() {

    float speed = (0.95 * Robot::oi->driveStick2->GetRawAxis(OI::LEFT_Y_AXIS_E));
    float turn = (1.0 * Robot::oi->driveStick2->GetRawAxis(OI::RIGHT_X_AXIS_E));

/*    if (Robot::oi->driveStick->GetRawButton(6)) {
        speed = 0.4 * speed;
        turn = 0.55 * turn;
}*/
    Robot::drivetrain->ArcadeDrive(speed, turn);
}

bool DriveWithJoystick::IsFinished() {

	return false;

}

void DriveWithJoystick::End() {
 	Robot::drivetrain->Stop();
}

void DriveWithJoystick::Interrupted() {
    End();
}

