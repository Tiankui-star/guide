#include <iostream>
#include<string>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
class buildings
{
public:

};
int main() {
    string map_name = "qdu_map.png";
    Mat img=imread(map_name, IMREAD_COLOR);
    imshow("map",img);
    waitKey(0);
    return 0;
}