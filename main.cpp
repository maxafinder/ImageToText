#include </usr/local/Cellar/opencv/4.5.2_4/include/opencv4/opencv2/imgcodecs.hpp>
#include </usr/local/Cellar/opencv/4.5.2_4/include/opencv4/opencv2/highgui.hpp>
#include </usr/local/Cellar/opencv/4.5.2_4/include/opencv4/opencv2/imgproc.hpp>
#include </usr/local/Cellar/opencv/4.5.2_4/include/opencv4/opencv2/opencv.hpp>
#include <string>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <iostream>


int main(int argc, char ** argv) {

  // Get the file path to the image, otherwise use the default
  std::string path;
  if (argc > 1) {
    path = argv[1];
  }
  else {
    path = "images/receipt2.png";
  }

  // Show the image specified by path
  cv::Mat img = cv::imread(path);
  cv::imshow("Image", img);

  // Create tesseract object to access the API
  tesseract::TessBaseAPI * ocr = new tesseract::TessBaseAPI();

  // Initialize tesseract to use English and the LSTM OCR Engine
  ocr->Init(NULL, "eng", tesseract::OEM_LSTM_ONLY);

  // Set page segmentation mode (default expects a page of text)
  ocr->SetPageSegMode(tesseract::PSM_AUTO);

  // Set the image
  ocr->SetImage(img.data, img.cols, img.rows, 3, img.step);

  // Get the output
  std::string outText = std::string(ocr->GetUTF8Text());

  // Print the output
  printf("OUTPUT:\n\n%s\n", outText.c_str());


  cv::waitKey(0);

  return 0;
}
