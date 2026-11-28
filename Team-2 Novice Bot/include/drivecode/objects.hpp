#include "lemlib/chassis/chassis.hpp"
#include "main.h"
//ignore the problem saying that main.h h isn't directly used, we still need it
#include "pros/motor_group.hpp"
#include "pros/motors.hpp"
extern pros::Controller controller;
extern pros::MotorGroup leftmotors;
extern pros::MotorGroup rightmotors;
extern lemlib::Drivetrain drivetrain;
extern pros::Motor lift;