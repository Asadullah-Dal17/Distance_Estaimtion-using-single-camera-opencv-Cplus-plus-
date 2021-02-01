#include <iostream>
#include <opencv2/opencv.hpp>
// using namespace cv;


// using namespace cv;
using namespace std;
int main(int, char**)
{
    cv::Mat frame;

    cv::CascadeClassifier faceDetector;

    double ScalingFactor =1;
    string harcascdePath= "haarcascade_frontalface_default.xml";
    
    // loading harcascade file
    faceDetector.load(harcascdePath);

    //--- INITIALIZE VIDEOCAPTURE
    
    cv::VideoCapture cap;
    // open the default camera using default API
    // cap.open(0);
    // OR advance usage: select any API backend
    int deviceID = 2;             // 0 = open default camera
    int apiID = cv::CAP_ANY;      // 0 = autodetect default API
    // open selected camera using selected API
    cap.open(deviceID, apiID);
    // check if we succeeded
    if (!cap.isOpened()) {
        cerr << "ERROR! Unable to open camera\n";
        return -1;
    }
    //--- GRAB AND WRITE LOOP
    cv::Mat Gray_frame;
    cout << "Start grabbing" << endl
        << "Press any key to terminate" << endl;
    while (true)
    {
        // wait for a new frame from camera and store it into 'frame'
        cap.read(frame);
        cv::cvtColor(frame, Gray_frame, cv::COLOR_BGR2GRAY);
        cv::imshow("gray", Gray_frame);
        
        // check if we succeeded
        if (frame.empty()) {
            cerr << "ERROR! blank frame grabbed\n";
            break;
        }
        // show live and wait for a key with timeout long enough to show images
        cv::imshow("Live", frame);
        int key =cv::waitKey(1);
        if (key =='q')
            break;
    }
    // the camera will be deinitialized automatically in VideoCapture destructor
    return 0;
}