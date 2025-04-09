//#include <opencv2/opencv.hpp>
//#include <iostream>
//
//using namespace cv;
//using namespace std;
//
//// ȫ�ֱ����洢����
//int g_x = 0;
//int g_y = 0;
//
//// ���ص�����
//void onMouse(int event, int x, int y, int flags, void* userdata) {
//    if (event == EVENT_MOUSEMOVE) {
//        g_x = x;
//        g_y = y;
//        cout << "X: " << g_x << ", Y: " << g_y << endl; // ʵʱ������굽����̨
//    }
//}
//
//int main() {
//    // ��ȡͼƬ
//    Mat image = imread("qdu_map.png"); // �滻Ϊ���ͼƬ·��
//    if (image.empty()) {
//        cout << "�޷�����ͼƬ��" << endl;
//        return -1;
//    }
//
//    namedWindow("Image");
//    setMouseCallback("Image", onMouse); // �������ص�����
//
//    while (true) {
//        // ��ͼƬ�ϻ��Ƶ�ǰ����
//        Mat displayImage = image.clone();
//        string coord = "X: " + to_string(g_x) + ", Y: " + to_string(g_y);
//        putText(displayImage, coord, Point(10, 30), FONT_HERSHEY_SIMPLEX, 0.7, Scalar(0, 255, 0), 2);
//
//        imshow("Image", displayImage);
//
//        // ��ESC�˳�
//        if (waitKey(10) == 27) break;
//    }
//
//    destroyAllWindows();
//    return 0;
//}