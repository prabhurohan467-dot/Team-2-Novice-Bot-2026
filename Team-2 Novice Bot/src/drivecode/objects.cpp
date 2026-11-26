#include "lemlib/chassis/chassis.hpp"
#include "pros/misc.h"
#include "pros/misc.hpp"
#include "pros/motor_group.hpp"
#include "pros/motors.hpp"
pros::MotorGroup leftmotors ({1,2}); //Change ports later
pros::MotorGroup rightmotors ({3,4});
pros::Controller controller (pros::E_CONTROLLER_MASTER);
lemlib::Drivetrain drivetrain( 
    &leftmotors,
    &rightmotors,
    0,
    0,
    0,
    0
); //I put 0 for all those because i don't know what they are yet they can be updated later
pros::Motor lift(5); //all ports should be changed later but for now lift is 5

