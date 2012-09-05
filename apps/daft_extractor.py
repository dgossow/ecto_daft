#!/usr/bin/env python
# 
# Copyright (c) 2011, Willow Garage, Inc.
# All rights reserved.
# 
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are met:
#     * Redistributions of source code must retain the above copyright
#       notice, this list of conditions and the following disclaimer.
#     * Redistributions in binary form must reproduce the above copyright
#       notice, this list of conditions and the following disclaimer in the
#       documentation and/or other materials provided with the distribution.
#     * Neither the name of the Willow Garage, Inc. nor the names of its
#       contributors may be used to endorse or promote products derived from
#       this software without specific prior written permission.
# 
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
# 

import ecto

from ecto_opencv.highgui import imshow
from ecto.opts import run_plasm, scheduler_options
from ecto_opencv.features2d import DrawKeypoints
from ecto_daft import daft

def parse_args():
    import argparse
    parser = argparse.ArgumentParser(description='Find a plane in an RGBD image.')
    scheduler_options(parser.add_argument_group('Scheduler'))
    options = parser.parse_args()

    return options


if __name__ == '__main__':
    options = parse_args()

    plasm = ecto.Plasm()

    #setup the input source, grayscale conversion
    from ecto_image_pipeline.io.source import create_source
    from ecto_openni import SXGA_RES, FPS_15, VGA_RES, FPS_30
    source = create_source('image_pipeline','OpenNISource',image_mode=SXGA_RES,image_fps=FPS_15)

    #
    mydaft = daft.DAFT(n_features=500)

    #
    kpdrawer = daft.DrawKeypoints3D()

    connections = [ # tunnel Kinect output to DAFT
                    source['K'] >> mydaft['K'],
                    source['depth'] >> mydaft['depth'],
                    source['image'] >> mydaft['image'],
                    source['mask'] >> mydaft['mask'],

                    # draw keypoints
                    source['image'] >> kpdrawer['image'],
                    mydaft['keypoints3d'] >> kpdrawer['keypoints3d'],
                    
                    # show the image
                    kpdrawer['image'] >> imshow(name='3D Keypoints',waitKey=1)[:],
                                        
                    # show the depth image
                    source['depth'] >> imshow(name='Depth',waitKey=1)[:],
                                        
                    ]
    
    plasm.connect(connections)
    run_plasm(options, plasm, locals=vars())
