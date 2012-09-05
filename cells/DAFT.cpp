#include <ecto/ecto.hpp>
#include <daft/daft.h>

using ecto::tendrils;

/** Cell for DAFT feature detection and descriptor extraction
 */
struct DAFT
{
  static void
  declare_params(tendrils& p)
  {
    p.declare<int>("n_features", "The number of desired features", 500);
  }

  static void
  declare_io(const tendrils& params, tendrils& inputs, tendrils& outputs)
  {
    inputs.declare < cv::Mat > ("image", "The image.");
    inputs.declare < cv::Mat > ("depth", "The depth image");
    inputs.declare < cv::Mat > ("mask", "A mask for rejecting keypoints.");
    inputs.declare < cv::Mat > ("K", "The intrinsic camera matrix");

    outputs.declare < std::vector<cv::KeyPoint> > ("keypoints", "The keypoints.");
    outputs.declare < std::vector<cv::KeyPoint3D> > ("keypoints3d", "The 3d keypoints (with 3d pose and size).");
    outputs.declare < cv::Mat > ("descriptors", "The descriptors per keypoints");
  }

  void
  configure(const tendrils& params, const tendrils& inputs, const tendrils& outputs)
  {
    cv::daft::DAFT::DetectorParams p_det;
    cv::daft::DAFT::DescriptorParams p_desc;

    p_det.max_num_kp_ = params.get<int>("n_features");

    DAFT_ = cv::daft::DAFT( p_det, p_desc );
  }

  int
  process(const tendrils& inputs, const tendrils& outputs)
  {
    // get inputs
    cv::Mat image, depth;
    cv::Mat1b mask;
    cv::Matx33f K;

    image = inputs.get< cv::Mat >("image");
    depth = inputs.get< cv::Mat >("depth");
    mask = inputs.get< cv::Mat >("mask");
    K = inputs.get< cv::Mat >("K");

    cv::Mat1f descriptors;
    std::vector<cv::KeyPoint3D> keypoints3d;

    DAFT_( image, mask, depth, K, keypoints3d, descriptors );

    //convert Keypoint3D to Keypoint
    std::vector<cv::KeyPoint> keypoints( keypoints3d.size() );

    for ( size_t i=0; i<keypoints3d.size(); i++ )
    {
      keypoints[i] = keypoints3d[i];
    }

    outputs["keypoints3d"] << keypoints3d;
    outputs["keypoints"] << keypoints;
    outputs["descriptors"] << cv::Mat(descriptors);

    return ecto::OK;
  }

  cv::daft::DAFT DAFT_;
};

ECTO_CELL(daft, DAFT, "DAFT",
    "A DAFT detector. Takes an rgbd image and a mask, and computes keypoints and descriptors.");
