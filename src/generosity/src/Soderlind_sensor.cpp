#include "ros/ros.h"
#include "std_msgs/UInt16.h"
#include <cstdlib>

int main(int argc, char **argv)
{
	//setup node
	ros::init (argc, argv, "Soderlind_sensor");
	ros::NodeHandle n;
	//publish to "random" topic 
	ros::Publisher chatter_pub =
		n.advertise<std_msgs::UInt16>("random", 1000);
	ros::Rate loop_rate(10);
	//get seed for "random" sensor data
	srand(time(0));	
	//loop allows exiting via ctrl-c
	while(ros::ok())
	{
		
		std_msgs::UInt16 msg;
		//generate random data between 0 and 99
		msg.data =  rand()%100;
		//publish data
		chatter_pub.publish(msg);
		ros::spinOnce();
		//pause before getting new data
		loop_rate.sleep();
	}

return 0;
}
