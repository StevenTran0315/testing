/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/FrisbeeManipulator.h"
#include "ctre/phoenix/motorcontrol/can/WPI_TalonSRX.h"
#include "WPILib.h"
#include "RobotMap.h"
using namespace ctre;

FrisbeeManipulator::FrisbeeManipulator() : Subsystem("ExampleSubsystem") {}

void FrisbeeManipulator::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  std::shared_ptr<frc::SpeedController> tmp = RobotMap::getMotor(RobotMap::shootMotor);
  shootMotor = std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_TalonSRX>(tmp);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void FrisbeeManipulator::ShootSpeed(float speed){
    shootMotor->Set(speed);
}