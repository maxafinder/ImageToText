#include </usr/local/Cellar/opencv/4.5.2_4/include/opencv4/opencv2/imgcodecs.hpp>
#include </usr/local/Cellar/opencv/4.5.2_4/include/opencv4/opencv2/highgui.hpp>
#include </usr/local/Cellar/opencv/4.5.2_4/include/opencv4/opencv2/imgproc.hpp>
#include <iostream>


int main() {
  std::string path = "images/receipt1.png";
  cv::Mat img = cv::imread(path);
  cv::imshow("Image", img);
  cv::waitKey(0);
  return 0;
}
