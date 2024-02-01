// Code to record webcam footage in different file formats
// used with readFileSize.cpp for comapring compression factor
// written by : Sanidhya

#include <iostream>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main()
{
   Mat image;
   namedWindow("Display Window");
   VideoCapture cap(0);

   int frame_width = static_cast<int>(cap.get(CAP_PROP_FRAME_WIDTH));
   int frame_height = static_cast<int>(cap.get(CAP_PROP_FRAME_HEIGHT));

   cout << frame_height << "\t \n" << frame_width << "\t \n ";
   Size frame_size(frame_width, frame_height);
   int frames_per_second = 30;

   bool recording = true; // required (refer end line : 109)

   // line by line explaination:
      // concatenates string of 4 chars to create fourcc code for file extension
      // instantiates object of class VideoWriter
      // Using the objects opens a resepactive extension file for given webcam stream
   
   // AVI format
   auto fourcc_avi = VideoWriter::fourcc('M', 'J', 'P', 'G'); 
   VideoWriter output_avi;
   output_avi.open("MOSSE_Tracking_AVI.avi", fourcc_avi, frames_per_second, frame_size, true);

   // MP4 format
   auto fourcc_mp4 = VideoWriter::fourcc('a', 'v', 'c', '1'); 
   VideoWriter output_mp4;
   output_mp4.open("MOSSE_Tracking_MP4.mp4", fourcc_mp4, frames_per_second, frame_size, true);

   // XVID
   auto fourcc_xvid = VideoWriter::fourcc('X', 'V', 'I', 'D'); 
   VideoWriter output_xvid;
   output_xvid.open("MOSSE_Tracking_XVID.avi", fourcc_xvid, frames_per_second, frame_size, true);

   //FLV
   auto fourcc_flv = VideoWriter::fourcc('F', 'L', 'V', '1'); 
   VideoWriter output_flv;
   output_flv.open("MOSSE_Tracking_FLV.flv", fourcc_flv, frames_per_second, frame_size, true);

   //MKV
   auto fourcc_mkv = VideoWriter::fourcc('H', '2', '6', '4'); 
   VideoWriter output_mkv;
   output_mkv.open("MOSSE_Tracking_MKV.mkv", fourcc_mkv, frames_per_second, frame_size, true);

   //MOV
   auto fourcc_mov = VideoWriter::fourcc('H', '2', '6', '4'); 
   VideoWriter output_mov;
   output_mov.open("MOSSE_Tracking_MOV.mov", fourcc_mov, frames_per_second, frame_size, true);

   //WEBM
   auto fourcc_webm = VideoWriter::fourcc('V', 'P', '9', '0'); 
   VideoWriter output_webm;
   output_webm.open("MOSSE_Tracking_WEBM.webm", fourcc_webm, frames_per_second, frame_size, true);

   //OGG
   auto fourcc_ogg = VideoWriter::fourcc('T', 'H', 'E', 'O'); 
   VideoWriter output_ogg;
   output_ogg.open("MOSSE_Tracking_OGG.ogg", fourcc_ogg, frames_per_second, frame_size, true);


// Loop to write frames in respective files
   while(recording)
   {
      auto start = chrono::system_clock::now();
      cap >> image;

      output_avi.write(image);
      output_mp4.write(image);
      output_xvid.write(image);
      output_flv.write(image);
      output_mkv.write(image);
      output_mov.write(image);
      output_webm.write(image);
      output_ogg.write(image);

      imshow("Display Window",image);
      auto key = waitKey(1);

      if (key == 27) // ESC
      {
         recording = false;
      }

      // Calculates and displays fps
      auto end= chrono::system_clock::now();
      chrono::duration<double> diff = end - start;
      cout << "Time to process last frame (seconds): " << diff.count() << "\t FPS: " << 1.0/diff.count() << "\n";
   }

// Release instances and objects

   output_avi.release();
   output_mp4.release();
   output_xvid.release();
   output_flv.release();
   output_mkv.release();
   output_mov.release();
   output_webm.release();
   output_ogg.release();

   cap.release();
   return 0;
}



// Earlier code didnt work as it was generating an interrupt to stop webcam instance
// This prevented the video to store an MOOV atom code, that defines file type at end stream
// refer : https://www.reddit.com/r/ffmpeg/comments/ih0hf7/ffmpeg_moov_atom_not_found/
// Hence created bool for recording, prevents interrupt and saves file ending