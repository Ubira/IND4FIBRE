# UR5 Use Case
This folder holds the ROS workspace to control the UR5 use cases for the IND4FIBRE project.

# Main Objective

Create a simple pick and place task for the UR5 manipulator controlled by a dedicated PC with ROS. The program should be a state machine that will be aware of the alarm system signals. If the alarm is activated, the manipulator must interrupt the task execution until the alarm deactivaton and, after this, continue to execute the task from where it stoped.