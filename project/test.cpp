//#include <opencv2/opencv.hpp>
//#include <iostream>
//
//using namespace cv;
//using namespace std;
//
//// 全局变量存储坐标
//int g_x = 0;
//int g_y = 0;
//
//// 鼠标回调函数
//void onMouse(int event, int x, int y, int flags, void* userdata) {
//    if (event == EVENT_MOUSEMOVE) {
//        g_x = x;
//        g_y = y;
//        cout << "X: " << g_x << ", Y: " << g_y << endl; // 实时输出坐标到控制台
//    }
//}
//
//int main() {
//    // 读取图片
//    Mat image = imread("qdu_map.png"); // 替换为你的图片路径
//    if (image.empty()) {
//        cout << "无法加载图片！" << endl;
//        return -1;
//    }
//
//    namedWindow("Image");
//    setMouseCallback("Image", onMouse); // 设置鼠标回调函数
//
//    while (true) {
//        // 在图片上绘制当前坐标
//        Mat displayImage = image.clone();
//        string coord = "X: " + to_string(g_x) + ", Y: " + to_string(g_y);
//        putText(displayImage, coord, Point(10, 30), FONT_HERSHEY_SIMPLEX, 0.7, Scalar(0, 255, 0), 2);
//
//        imshow("Image", displayImage);
//
//        // 按ESC退出
//        if (waitKey(10) == 27) break;
//    }
//
//    destroyAllWindows();
//    return 0;
//}