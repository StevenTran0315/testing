/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/


#ifndef ROBOTMAP_H

#define ROBOTMAP_H

#include "frc/WPILib.h"

class RobotMap {
public:
    RobotMap();
	static std::shared_ptr<frc::DoubleSolenoid> gearSolenoid;
	std::shared_ptr<frc::Encoder> getEncoder();
	std::shared_ptr<frc::SpeedController> getMotor();
	std::shared_ptr<frc::ADXRS450_Gyro> getGyro();
	std::shared_ptr<frc::DoubleSolenoid> getSolenoid();

	std::shared_ptr<frc::Compressor> getCompressor();
	
	static std::shared_ptr<frc::SpeedController> shootMotor;

	// Drivetrain subsystem
	static std::shared_ptr<frc::ADXRS450_Gyro> gyro;
	static std::shared_ptr<frc::Encoder> leftDriveEncoder;
	static std::shared_ptr<frc::Encoder> rightDriveEncoder;
	
    static std::shared_ptr<frc::SpeedController> frontLeftDrive;
    static std::shared_ptr<frc::SpeedController> backLeftDrive;
    static std::shared_ptr<frc::SpeedController> frontRightDrive;
    static std::shared_ptr<frc::SpeedController> backRightDrive;
    static std::shared_ptr<frc::DifferentialDrive> differentialDrive;
    static std::shared_ptr<frc::SpeedControllerGroup> leftDrive;
    static std::shared_ptr<frc::SpeedControllerGroup> rightDrive;
    static std::shared_ptr<frc::Compressor> compressorMain;


	static void init();
	static void reset();
};

#endif // ROBOTMAP_H