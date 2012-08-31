#include <ecto/ecto.hpp>
#include <daft/daft.h>

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
    inputs.declare < cv::Mat > ("K", "The intrinsic camera matrix");
    inputs.declare < cv::Mat > ("mask", "A mask for rejecting keypoints.");
    inputs.declare < std::vector<cv::KeyPoint> > ("keypoints", "The keypoints.");
    inputs.declare < cv::Mat > ("points", "2d points.");

    outputs.declare < std::vector<cv::KeyPoint> > ("keypoints", "The keypoints.");
    outputs.declare < cv::Mat > ("descriptors", "The descriptors per keypoints");
  }

  void
  configure(const tendrils& params, const tendrils& inputs, const tendrils& outputs)
  {
    /*
     cv::DAFT::CommonParams DAFT_params;
     DAFT_params.first_level_ = 0;
     DAFT_params.n_levels_ = params.get<int>("n_levels");
     DAFT_params.scale_factor_ = params.get<float>("scale_factor");
     DAFT_ = cv::DAFT(params.get<int>("n_features"), DAFT_params);
     */
  }

  int
  process(const tendrils& inputs, const tendrils& outputs)
  {
    /*
     std::vector < cv::KeyPoint > keypoints;
     inputs["keypoints"] >> keypoints;
     cv::Mat image, mask;
     inputs["image"] >> image;
     inputs["mask"] >> mask;
     cv::Mat desc;
     DAFT_(image, mask, keypoints, desc, !keypoints.empty()); //use the provided keypoints if they were given.
     if (!mask.empty())
     {
     //need to do keypoint validation as DAFT is broken.
     cv::Mat good_desc;
     std::vector < cv::KeyPoint > good_keypoints;
     good_keypoints.reserve(keypoints.size());
     good_desc.reserve(32 * keypoints.size());
     for (int i = 0, end = keypoints.size(); i < end; ++i)
     {
     const cv::Point2f& p2d = keypoints[i].pt;
     int u = p2d.x + 0.5f;
     int v = p2d.y + 0.5f;
     if (mask.at < uchar > (v, u))
     {
     good_keypoints.push_back(keypoints[i]);
     good_desc.push_back(desc.row(i));
     }
     }
     outputs["keypoints"] << good_keypoints;
     outputs["descriptors"] << good_desc;
     }
     else
     {
     outputs["keypoints"] << keypoints;
     outputs["descriptors"] << desc;
     }
     */
    return ecto::OK;
  }

  cv::DAFT DAFT_;
};

ECTO_CELL(features2d, DAFT, "DAFT",
    "A DAFT detector. Takes an rgbd image and a mask, and computes keypoints and descriptors.");
