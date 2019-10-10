/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include "RobotMap.h"
#include "frc/WPILib.h"
class Drivetrain : public frc::Subsystem {
 private:
  std::shared_ptr<frc::ADXRS450_Gyro> gyro;
  std::shared_ptr<frc::Encoder> leftDriveEncoder;
  std::shared_ptr<frc::Encoder> rightDriveEncoder;
  std::shared_ptr<frc::DifferentialDrive> differentialDrive;

 public:
  std::shared_ptr<frc::SpeedControllerGroup> leftDrive;
  std::shared_ptr<frc::SpeedControllerGroup> rightDrive;
  std::shared_ptr<frc::SpeedController> frontLeftDrive;  
  std::shared_ptr<frc::SpeedController> backLeftDrive;
  std::shared_ptr<frc::SpeedController> frontRightDrive;
  std::shared_ptr<frc::SpeedController> backRightDrive;
  std::shared_ptr<frc::DoubleSolenoid> gearSolenoid;
  std::shared_ptr<frc::DoubleSolenoid> climbSolenoid;
  std::shared_ptr<frc::Compressor> compressor;


  Drivetrain();
  void InitDefaultCommand();
  void Reset();
  void TankDrive(double leftspeed, double rightspeed);
  void ArcadeDrive(double speed, double turn);
  void Stop();
  void ResetEncoder();
  float GetLeftCount();
  float GetRightCount();
  void ReverseGear();
	void ForwardGear();
  void ClimbIn();
  void ClimbOut();
  void CompressorSwitch();


  // Solenoid Variables
  bool skiExtended;
  bool highGear;
  bool compressorOn;
 
};
 // DRIVETRAIN_H
