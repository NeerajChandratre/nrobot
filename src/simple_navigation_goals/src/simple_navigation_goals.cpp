#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>
#include <iostream>
#include <array>
#include <chrono>
#include <thread>
using namespace std;
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;
int main(int argc, char** argv)
{
  int g;
  float r[10] =  {-0.55, 0.05, 3.55, -6.8}, s[10] = {-7.05, 0.05, -4.1, -4.4}, t[10] = {1,1,1,1};
  ros::init(argc, argv, "simple_navigation_goals");
  MoveBaseClient ac("move_base", true);//tell the action client that we want to spin a thread by default
  while(  !ac.waitForServer( ros::Duration(5.0) )  )//wait for the action server to come up
  {
    ROS_INFO("Waiting for the move_base action server to come up");
  }
  move_base_msgs::MoveBaseGoal goal;
  goal.target_pose.header.frame_id = "odom";//we'll send a goal to the robot to move 1 meter forward
  goal.target_pose.header.stamp = ros::Time::now();
  for(g = 0; g < 4; g++)
  {
    goal.target_pose.pose.position.x = r[g];
    goal.target_pose.pose.position.y = s[g];
    goal.target_pose.pose.orientation.w = t[g];
    ROS_INFO("Sending goal");
    ac.sendGoal(goal);
    ac.waitForResult();
    if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    {
      ROS_INFO("Hooray, the base moved x meter forward");
      this_thread::sleep_for(chrono::milliseconds(10000));
    }
    else
    {
      ROS_INFO("The base failed to move forward x meter for some reason");
    }
  }
  return 0;
}
