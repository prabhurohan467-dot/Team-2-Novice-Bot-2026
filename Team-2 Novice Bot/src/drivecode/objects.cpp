
#include "pros/misc.h"
#include "pros/misc.hpp"
#include "objects.hpp"
pros::MotorGroup leftmotors ({1,2}); //Change ports later
pros::MotorGroup rightmotors ({3,4});
pros::Controller controller (pros::E_CONTROLLER_MASTER);
lemlib::Drivetrain drivetrain( 
    &leftmotors,
    &rightmotors,
    0, /*the track width of the robot, in inches. 
    This is the distance from the left wheels to the right wheels */
    0, //The diameter of the wheel used on the drivetrain, in inches
    0, //The rpm of the wheels
    0 //Always set the horizontal drift to zero bc "Zachary says so" 
    /*For the last value, it may or may not be changed 
    bc it says on the Lemlib documentation that it should be 8 */
); 
pros::Motor lift(5); //all ports should be changed later but for now lift is 5

