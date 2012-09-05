#include <ecto/ecto.hpp>
//#include "interfaces.h"
#include <daft/keypoint3d.h>

using ecto::tendrils;


/** Interface to cv::drawKeypoints3d, to draw 3d keypoints to an image
 */
struct DrawKeypoints3D
{
  typedef std::vector<cv::KeyPoint3D> kpts_t;
  typedef DrawKeypoints3D C;
  static void
  declare_io(const tendrils& params, tendrils& inputs, tendrils& outputs)
  {
    inputs.declare(&C::in_image, "image", "The input image, used as the base to draw on.");
    inputs.declare(&C::in_kpts, "keypoints3d", "The keypoints to draw.");
    outputs.declare(&C::out_image, "image", "The output image.");
  }

  int
  process(const tendrils& inputs, const tendrils& outputs)
  {
    *out_image = cv::Mat(); //reset the output... mthreaded
    cv::drawKeypoints3D(*in_image, *in_kpts, *out_image, cv::Scalar(255,0,0), cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS );
    return ecto::OK;
  }
  ecto::spore<cv::Mat> in_image, out_image;
  ecto::spore<kpts_t> in_kpts;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ECTO_CELL(daft, DrawKeypoints3D, "DrawKeypoints3D", "Draws 3D keypoints.");
