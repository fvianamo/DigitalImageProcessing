#include <iostream>
#include <cv.h>
#include "opencv2/highgui/highgui.hpp" //that's the right way to import highgui lib
//#include <highgui.h> //wrong way to import the lib, have no idea why


using namespace cv;
using namespace std;

int main(int, char**){
  Mat image;

  image= imread("bolhas.png",CV_LOAD_IMAGE_GRAYSCALE); //import an image into the variable, second argument forces gray scale 
  if(!image.data) //check if the image was loaded successfully 
    cout << "nao abriu bolhas.png" << endl;

  namedWindow("janela",WINDOW_AUTOSIZE); //creates an autoscaled window called janela

  for(int i=200;i<210;i++){ // forces the retangle (200,210 - 10,200) to be black "0"
    for(int j=10;j<200;j++){
      image.at<uchar>(i,j)=0;
    }
  }
  
  imshow("janela", image); //shows the modified image on the screen  
  waitKey(); //wait for any key to be pressed

  image= imread("bolhas.png",CV_LOAD_IMAGE_COLOR); // load bolhas.png on its original colors 

  Vec3b  val; // creates the color combination for red in a vector of unsigned char
  //Vec for vector, 3 for lenght and b for type (uchar)

  val[0] = 0;   //B
  val[1] = 0;   //G
  val[2] = 255; //R
  
  for(int i=200;i<210;i++){ //change retangle color to red
    for(int j=10;j<200;j++){
      image.at<Vec3b>(i,j)=val;
    }
  }

  imshow("janela", image);  //shows image on the window
  waitKey(); //waits for user's input
  return 0; //algorithm ends
}
