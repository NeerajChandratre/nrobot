# nrobot
### Steps for running this code
1. In first terminal, launch gazebo `roslaunch njcrobot_gazebo robot.launch`
2. In second terminal, launch Rviz `roslaunch njcrobot_description njcrobot_rviz.launch` (select the fixed frame to 'odom')
3. In third terminal, launch AMCL `roslaunch njcrobot_navigation amcl_demo.launch` (change the directory name in the first line of test_map.yaml file to your directory)
4. In fourth terminal, launch simple_navigation_goals code `rosrun simple_navigation_goals simple_navigation_goals src/`
### Usage of this code
The output of this code results in the autonomous navigation of a '6 wheeled robot.' The robot navigates the four locations mentioned in the simple_navigation_goals.cpp file and also stops at each location for 10 seconds. This functionality can be useful for garden robots or for any other purposes.
### Components used here
1. Hokuyo laser
2. 6 Wheeled robot
3. Camera(optional)
### How it's made
1. Robot :- I made the robot by fitting 4 caster wheels at the four ends of the chassis. In the middle part, I attached two wheels. I further calculated the Mass Moment of Inertia of Wheel and Chassis. I installed laser and camera.
2. Map:- Created a custom map on gazebo for testing
3. Map(using Gmapping Package):- I created a map for autonomous navigation.
4. Navigation:- I ran the code for AMCL. Then I further made the robot completely autonomous by giving it the locations using the code in the simple_navigation_goals.cpp file.
