#include <yarp/os/Thread.h>
#include <yarp/sig/Vector.h>
#include <yarp/sig/Matrix.h>
#include <boost/thread/thread.hpp>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/features/normal_3d.h>
#include <iCub/data3D/minBoundBox.h>
#include <iCub/data3D/boundingBox.h>

struct DataToShow
{
    pcl::PointCloud<pcl::PointXYZRGB> cloud;
    pcl::PointCloud<pcl::Normal> normals;
    pcl::PointCloud<pcl::PointXYZ> sampled_cloud;
    iCub::data3D::BoundingBox boundingBox;
    std::string hand;
};

class VisualizationThread : public yarp::os::Thread
{
private:
    DataToShow &data;
    bool running;
    bool fromFile;

public:

    VisualizationThread(DataToShow &_data);
    ~VisualizationThread() {};

    void onStop();
    void run(); 
};