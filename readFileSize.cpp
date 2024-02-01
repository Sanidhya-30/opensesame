// Uses sys to read and compare file size of stored webcam footages in different formats

#include "opencv4/opencv2/highgui/highgui.hpp"
#include <iostream>
#include <sys/stat.h>

using namespace cv;
using namespace std;

int main()
{
    // List of video files to check
    vector<string> videoFiles = {"/home/ubuntu/opensesame/MOSSE_Tracking_AVI.avi",
                                 "/home/ubuntu/opensesame/MOSSE_Tracking_MP4.mp4",
                                 "/home/ubuntu/opensesame/MOSSE_Tracking_XVID.avi",
                                 "/home/ubuntu/opensesame/MOSSE_Tracking_FLV.flv",
                                 "/home/ubuntu/opensesame/MOSSE_Tracking_MKV.mkv",
                                 "/home/ubuntu/opensesame/MOSSE_Tracking_MOV.mov",
                                 "/home/ubuntu/opensesame/MOSSE_Tracking_WEBM.webm",
                                 "/home/ubuntu/opensesame/MOSSE_Tracking_OGG.ogg"};

    for (const string& videoFile : videoFiles) {
        struct stat fileInfo;
        if (stat(videoFile.c_str(), &fileInfo) == 0) {
            // Get file size in kilobytes
            long long fileSizeKB = fileInfo.st_size / 1024;

            // Check if file size is non-zero
            if (fileSizeKB > 0) {
                cout << "File: " << videoFile << "\n" ;
                cout << "File size: " << fileSizeKB << " KB\n";
            } else {
                cout << "Invalid file size for file: " << videoFile << "\n";
            }
        } else {
            cout << "Cannot retrieve file information for: " << videoFile << "\n";
        }
    }

    return 0;
}
