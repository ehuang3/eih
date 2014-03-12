#include <ros/ros.h>
#include <nodelet/nodelet.h>
#include <image_transport/image_transport.h>
#include <sensor_msgs/image_encodings.h>
#include <dynamic_reconfigure/server.h>
#include <image_proc/DebayerConfig.h>

#include <opencv2/imgproc/imgproc.hpp>

#include <cv_bridge/cv_bridge.h>

namespace eih
{
	class DebayerNodelet: public nodelet::Nodelet
	{
	public:
		DebayerNodelet(){}

	private:
		virtual void onInit(){
			// Get nodehandles
			ros::NodeHandle &nh = getMTNodeHandle();
			ros::NodeHandle &pnh = getMTPrivateNodeHandle();

			// Get image_raw topic through ros
			std::string img_topic;
			// pnh.param<std::string>("");

			NODELET_DEBUG("Initializing Nodelet!...");
		}

		void debayerCB(const sensor_msgs::Image::ConstPtr& msg)
		{
			static int i = 0;
			std::cout << "Received image: " << i++ << std::endl;
		}

		ros::Subscriber image_raw_subscriber;
		ros::Publisher image_color_publisher;
	};
}

// Register nodelet
#include <pluginlib/class_list_macros.h>
PLUGINLIB_DECLARE_CLASS(eih, MyNodeletClass, eih::DebayerNodelet, nodelet::Nodelet)
