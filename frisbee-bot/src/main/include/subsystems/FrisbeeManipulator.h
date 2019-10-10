/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include "frc/WPILib.h"

class FrisbeeManipulator : public frc::Subsystem {
 private:
    std::shared_ptr<ctre::phoenix::motorcontrol::can::WPI_TalonSRX> shootMotor;
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

 public:
  FrisbeeManipulator();
  void InitDefaultCommand() override;
  void ShootSpeed(float speed);
};
