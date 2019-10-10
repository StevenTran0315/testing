#include "RobotMap.h"
#include "../include/Robot.h"
#include "ctre/Phoenix.h"

namespace ctre_can = ctre::phoenix::motorcontrol::can;

        // Solenoids
#define SHOOT_SOLENOID_PORT 8
#define ADJUST_SOLENOID_PORT 4

        // Motors
#define SHOOTY_MOTOR_PORT 5

		// Drivetrain subsystem
#define FRONT_LEFT_DRIVE_PORT 2
#define BACK_LEFT_DRIVE_PORT 3
#define FRONT_RIGHT_DRIVE_PORT 0
#define BACK_RIGHT_DRIVE_PORT 1


static std::shared_ptr<frc::SpeedController> frontLeftDrive;
static std::shared_ptr<frc::SpeedController> backLeftDrive;
static std::shared_ptr<frc::SpeedController> frontRightDrive;
static std::shared_ptr<frc::SpeedController> backRightDrive;
static std::shared_ptr<frc::DifferentialDrive> differentialDrive;
static std::shared_ptr<frc::SpeedControllerGroup> leftDrive;
static std::shared_ptr<frc::SpeedControllerGroup> rightDrive;
static std::shared_ptr<frc::Compressor> compressorMain;
static std::shared_ptr<frc::SpeedController> shootMotor;

RobotMap::RobotMap(){
	backLeftDrive.reset(new ctre::phoenix::motorcontrol::can::WPI_VictorSPX(3));
	std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_VictorSPX>(backLeftDrive)->SetName("Drivetrain", "back left drive");

	backRightDrive.reset(new ctre::phoenix::motorcontrol::can::WPI_VictorSPX(1));
	std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_VictorSPX>(backRightDrive)->SetName("Drivetrain", "back right drive");

	frontLeftDrive.reset(new ctre::phoenix::motorcontrol::can::WPI_VictorSPX(2));
	std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_VictorSPX>(frontLeftDrive)->SetName("Drivetrain", "front left drive");

	frontRightDrive.reset(new ctre::phoenix::motorcontrol::can::WPI_VictorSPX(0));
    std::dynamic_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_VictorSPX>(frontRightDrive)->SetName("Drivetrain", "front right drive");

	shootMotor.reset(new ctre::phoenix::motorcontrol::can::WPI_TalonSRX(5));
	std::static_pointer_cast<ctre::phoenix::motorcontrol::can::WPI_TalonSRX>(shootMotor)->SetName("ShootMotor");
}

void RobotMap::reset() {

	}

/* SRC_ROBOTMAP_CPP_ */ 