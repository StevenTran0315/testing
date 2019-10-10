/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

#include <frc/WPILib.h>

OI::OI() {
  // Process operator interface input here.
  driveStick.reset(new frc::Joystick(0));
	driveStick2.reset(new frc::Joystick(1));

	// Drive Stick Buttons
	aButtonP = new frc::JoystickButton(driveStick.get(), 1);
	bButtonP = new frc::JoystickButton(driveStick.get(), 2);
	xButtonP = new frc::JoystickButton(driveStick.get(), 3);
	yButtonP = new frc::JoystickButton(driveStick.get(), 4);
	leftBumperButtonP = new frc::JoystickButton(driveStick.get(), 5);
	rightBumperButtonP = new frc::JoystickButton(driveStick.get(), 6);
	selectButtonP = new frc::JoystickButton(driveStick.get(), 7);
	startButtonP = new frc::JoystickButton(driveStick.get(), 8);
	leftStickButtonP = new frc::JoystickButton(driveStick.get(), 9);
	rightStickButtonP = new frc::JoystickButton(driveStick.get(), 10);


	// Drive Stick Buttons
	xButtonS = new frc::JoystickButton(driveStick2.get(), 1); //'[]' on PS
	aButtonS = new frc::JoystickButton(driveStick2.get(), 2); //'X' on PS
	bButtonS = new frc::JoystickButton(driveStick2.get(), 3); //'O' on PS
	yButtonS = new frc::JoystickButton(driveStick2.get(), 4); //'/\' on PS
	leftBumperButtonS = new frc::JoystickButton(driveStick2.get(), 5); //'L1' on PS
	rightBumperButtonS = new frc::JoystickButton(driveStick2.get(), 6); //'R1' on PS
	leftTriggerButtonS = new frc::JoystickButton(driveStick2.get(), 7); //'L2' on PS
	rightTriggerButtonS = new frc::JoystickButton(driveStick2.get(), 8); //'R2' on PS
	selectButtonS = new frc::JoystickButton(driveStick2.get(), 9); //'Share/Back' on PS
	startButtonS = new frc::JoystickButton(driveStick2.get(), 10); //'Start' on PS
	leftStickButtonS = new frc::JoystickButton(driveStick2.get(), 11); //'L3' on PS
	rightStickButtonS = new frc::JoystickButton(driveStick2.get(), 12); //'R3' on PS
	homeButtonS = new frc::JoystickButton(driveStick2.get(), 13); //'PS' on PS
}

std::shared_ptr<frc::Joystick> OI::getDriveStick() {
	return driveStick;
}

std::shared_ptr<frc::Joystick> OI::getDriveStick2() {
	return driveStick2;
}