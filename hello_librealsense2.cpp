
// License: Apache 2.0. See LICENSE file in root directory.
// Copyright(c) 2017 Intel Corporation. All Rights Reserved.

#include <librealsense2/rs.hpp>
#include <librealsense2/hpp/rs_internal.hpp>
#include <iostream>

int main()
{
    rs2::context ctx;

    std::cout << "hello from librealsense - " << RS2_API_VERSION_STR << std::endl;
    std::cout << "You have " << ctx.query_devices().size() << " RealSense devices connected" << std::endl;

    // Create a Pipeline - this serves as a top-level API for streaming and processing frames
    rs2::pipeline p;

    // Configure and start the pipeline
    p.start();

    // Block program until frames arrive
    rs2::frameset frames = p.wait_for_frames();

    // Try to get a frame of a depth image
    rs2::depth_frame depth = frames.get_depth_frame();

    // Get the depth frame's dimensions
    float width = depth.get_width();
    float height = depth.get_height();

    // Query the distance from the camera to the object in the center of the image
    float dist_to_center = depth.get_distance(width / 2, height / 2);

    // Print the distance
    std::cout << "The camera is facing an object " << dist_to_center << " meters away" << std::endl;

    return 0;
}
