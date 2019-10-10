/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Drivetrain.h"
#include "RobotMap.h"
#include "commands/DriveWithJoystick.h"
#include "Robot.h"
#include "OI.h"


Drivetrain::Drivetrain() : Subsystem("Drivetrain") {
  printf("%s  %d\n", __FUNCTION__, __LINE__);
  leftDriveEncoder = RobotMap::getEncoder(RobotMap::leftDrive);
  rightDriveEncoder = RobotMap::getEncoder(RobotMap::rightDrive);

  differentialDrive = RobotMap::getDiffDrive();
  leftDrive = RobotMap::getDriveGroup(RobotMap::leftDrive);
  rightDrive = RobotMap::getDriveGroup(RobotMap::rightDrive);

  backLeftDrive = RobotMap::getDriveMotor(RobotMap::backLeftDrive);
  frontLeftDrive = RobotMap::getDriveMotor(RobotMap::frontLeftDrive);
  backRightDrive = RobotMap::getDriveMotor(RobotMap::backRightDrive);
  frontRightDrive = RobotMap::getDriveMotor(RobotMap::frontRightDrive);


  compressor = RobotMap::getCompressor(RobotMap::compressorMain);

  compressorOn = false;
  
}
 
void Drivetrain::InitDefaultCommand() {
 SetDefaultCommand(new DriveWithJoystick());
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  
}

void Drivetrain::Reset() {
  if (gearSolenoid != nullptr) { 
    gearSolenoid->Set(frc::DoubleSolenoid::Value::kForward);
  }

  if (climbSolenoid != nullptr) {
    climbSolenoid->Set(frc::DoubleSolenoid::Value::kForward);
  }

  if (compressor != nullptr) {
    compressor->SetClosedLoopControl(false);
  }
}

void Drivetrain::ArcadeDrive(double speed, double turn){
  differentialDrive->ArcadeDrive(speed, turn);
}

void Drivetrain::Stop(){
    ArcadeDrive(0,0);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
  void Drivetrain::TankDrive(double leftspeed, double rightspeed){
  differentialDrive->TankDrive(leftspeed, rightspeed);
}

void Drivetrain:: ResetEncoder(){
    rightDriveEncoder->Reset();
    leftDriveEncoder->Reset();
}

float Drivetrain::GetRightCount(){
      return rightDriveEncoder->Get();
 }
  
float Drivetrain::GetLeftCount(){
    return leftDriveEncoder->Get();
}

void Drivetrain::ReverseGear(){
  if (gearSolenoid != nullptr) {
    gearSolenoid->Set(frc::DoubleSolenoid::Value::kReverse);  
  }
  highGear = false;
}

void Drivetrain::ForwardGear(){
  if (gearSolenoid != nullptr) {
    gearSolenoid->Set(frc::DoubleSolenoid::Value::kForward);
  }
  highGear = true; 
}

void Drivetrain::ClimbOut(){
  if (climbSolenoid != nullptr) {
    climbSolenoid->Set(frc::DoubleSolenoid::Value::kReverse);
  }
  skiExtended = true; 
  //rightClimbSolenoid->Set(frc::DoubleSolenoid::Value::kForward); 
}

void Drivetrain::ClimbIn(){
  if (climbSolenoid != nullptr) {
    climbSolenoid->Set(frc::DoubleSolenoid::Value::kForward); 
  }
  skiExtended = false;
  //rightClimbSolenoid->Set(frc::DoubleSolenoid::Value::kReverse); 
}

void Drivetrain::CompressorSwitch(){
  if (compressorOn){
    compressorOn = false;
    printf("%s  %d  compress= %d OFF\n", __FUNCTION__, __LINE__, compressorOn);
    if (compressor != nullptr) {
      compressor->SetClosedLoopControl(compressorOn);
    }
  }else {
    compressorOn = true;
    printf("%s  %d  compress= %d OFF\n", __FUNCTION__, __LINE__, compressorOn);
    if (compressor != nullptr) {
      compressor->SetClosedLoopControl(compressorOn);
    }
  }
  frc::SmartDashboard::PutBoolean("Compressor Status", compressorOn);
}