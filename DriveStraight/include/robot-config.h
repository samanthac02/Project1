using namespace vex;

extern brain Brain;

// VEXcode devices
extern inertial Inertial5;
extern motor ForwardLeft;
extern motor ForwardRight;
extern motor BackLeft;
extern motor BackRight;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );