#include "ros/ros.h"
//#include "std_msgs/String.h"
#include "std_msgs/UInt16.h"
//#include <cmath>

void processData(const std_msgs::UInt16 msg){
//process recieved data into ROS_INFO
ROS_INFO("Soderlind sensor said: %d", msg.data);
int newval = 10* msg.data;
ROS_INFO("Dritlein DUANE said: [%d]", newval);
}

int main(int argc, char **argv){

//setup node
ros::init(argc, argv, "Dritlein_DUANE");
ros::NodeHandle n;
//subscripe to "random" topic
ros::Subscriber sub = n.subscribe("random", 1000, processData);
//enter loop
ros::spin();

return 0;
}
