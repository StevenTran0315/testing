/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include "frc/WPILib.h"

class OI {
 public:
  OI();
  std::shared_ptr<frc::Joystick> getDriveStick();
	std::shared_ptr<frc::Joystick> getDriveStick2();

  std::shared_ptr<frc::Joystick> driveStick; //DriveTrain Controller (PS4 Port 0)
	std::shared_ptr<frc::Joystick> driveStick2; //Emergency Controller (XBOX Port 1)

	// Drive Stick Buttons
	frc::JoystickButton *aButtonS;
	frc::JoystickButton *bButtonS;
	frc::JoystickButton *xButtonS;
	frc::JoystickButton *yButtonS;
	frc::JoystickButton *leftBumperButtonS;
	frc::JoystickButton *rightBumperButtonS;
	frc::JoystickButton *selectButtonS;
	frc::JoystickButton *startButtonS;
	frc::JoystickButton *leftStickButtonS;
	frc::JoystickButton *rightStickButtonS;
	frc::JoystickButton *leftTriggerButtonS;
	frc::JoystickButton *rightTriggerButtonS;
	frc::JoystickButton *homeButtonS;
	frc::JoystickButton *touchpadButtonS;

	frc::JoystickButton *aButtonP;
	frc::JoystickButton *bButtonP;
	frc::JoystickButton *xButtonP;
	frc::JoystickButton *yButtonP;
	frc::JoystickButton *leftBumperButtonP;
	frc::JoystickButton *rightBumperButtonP;
	frc::JoystickButton *selectButtonP;
	frc::JoystickButton *startButtonP;
	frc::JoystickButton *leftStickButtonP;
	frc::JoystickButton *rightStickButtonP;

	// Axies for controller
	static const int LEFT_X_AXIS = 0;	//Logitech
	static const int LEFT_Y_AXIS = 1;
	static const int LEFT_TRIGGER_AXIS = 3;
	static const int RIGHT_TRIGGER_AXIS = 2;
	static const int RIGHT_X_AXIS = 4;
	static const int RIGHT_Y_AXIS = 5;

	static const int LEFT_X_AXIS_E = 0; 	//PS4
	static const int LEFT_Y_AXIS_E = 1;
	static const int LEFT_TRIGGER_AXIS_E = 3;
	static const int RIGHT_TRIGGER_AXIS_E = 4;
	static const int RIGHT_X_AXIS_E = 2;
	static const int RIGHT_Y_AXIS_E = 5;
};
