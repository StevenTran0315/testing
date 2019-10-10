/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/CompressorSwitch.h"
#include "subsystems/Drivetrain.h"

CompressorSwitch::CompressorSwitch() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(Robot::drivetrain.get());
}

// Called just before this Command runs the first time
void CompressorSwitch::Initialize() {
   if (Robot::oi->driveStick2->GetRawButton(9)) {
    Robot::drivetrain->compressorOn = true;
    if (Robot::drivetrain->compressor != nullptr) {
      Robot::drivetrain->compressor->SetClosedLoopControl(Robot::drivetrain->compressorOn);
    }
  } 
  else {
    Robot::drivetrain->compressorOn = false;
    if (Robot::drivetrain->compressor != nullptr) {
      Robot::drivetrain->compressor->SetClosedLoopControl(Robot::drivetrain->compressorOn);
    }
}
}

// Called repeatedly when this Command is scheduled to run
void CompressorSwitch::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool CompressorSwitch::IsFinished() { return false; }

// Called once after isFinished returns true
void CompressorSwitch::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CompressorSwitch::Interrupted() {}
