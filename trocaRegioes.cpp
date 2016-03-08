#include <iostream>
#include <cv.h>
#include "opencv2/highgui/highgui.hpp" //that's the right way to import highgui lib
#define NSUBIMAGES 4

using namespace cv;
using namespace std;

int main(int, char** argv){
    Mat img;
    
    img = imread(argv[1], CV_LOAD_IMAGE_GRAYSCALE);
    
    if (!img.data) {
        cout << "Image " << argv[1] << " could not be opened";
    }
    
    namedWindow("mainWindow", WINDOW_AUTOSIZE);
    
    imshow("mainWindow", img);
    
    int imgRows = img.rows;
    int imgCols = img.cols;
    
    cout << "image size: " << imgRows << "x" << imgCols << endl;
    
    int subImageRows = imgRows/(NSUBIMAGES/2);
    int subImageCols = imgCols/(NSUBIMAGES/2);
    
    cout << "sub image size: " << subImageRows << "x" << subImageCols << endl;
    
    vector<int> vert;
    
    for (int i =0 ; i < NSUBIMAGES/2; i++) {
        for (int j = 0; j < NSUBIMAGES/2; j++) {
            vert.push_back(i*subImageRows);
            vert.push_back(j*subImageCols);
            cout << "vertice: (" << i*subImageRows << "," << j*subImageCols << ")" << endl;
        }
    }
    
    vector<Mat> subImgs;
    
    for (int i = 0; i < NSUBIMAGES/2; i++) {
        subImgs.push_back(Mat(img, Rect(vert.at(2*i), vert.at(2*i+1), subImageCols, subImageRows)));
        cout << "Sub Image created !" << endl;
    }
    
    
    namedWindow("subImage1", WINDOW_AUTOSIZE);
    namedWindow("subImage2", WINDOW_AUTOSIZE);
    //namedWindow("subImage3", WINDOW_AUTOSIZE);
    //namedWindow("subImage4", WINDOW_AUTOSIZE);
    
    imshow("subImage1", subImgs.at(0));
    //cout << "subImage size: (" << subImgs.at(0).rows << "," << subImgs.at(0).cols << ")" << endl;
    imshow("subImage2", subImgs.at(1));
    //imshow("subImage3", subImgs.at(2));
    //imshow("subImage4", subImgs.at(3));
    
    
    waitKey(); //waits for user's input
    return 0; //algorithm ends
}
