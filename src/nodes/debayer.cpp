#include <sensor_msgs/Image.h>
#include <pluginlib/class_list_macros.h>

// Watch the capitalization carefully
PLUGINLIB_DECLARE_CLASS(eih, MyNodeletClass, eih::DebayerNodelet, nodelet::Nodelet)

namespace eih
{
	class DebayerNodelet: public nodelet::Nodelet
	{
	public:
		DebayerNodelet(){}

		virtual void onInit()
		{
			NODELET_DEBUG("Initializing Nodelet!...");
		}
	};
}
