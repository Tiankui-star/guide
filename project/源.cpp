#include <iostream>
#include<string>
#include"building.h"
#include <opencv2/opencv.hpp>
#include<thread>
#include<windows.h>
#include"function.h"
#include<map>
using namespace std;
using namespace cv;
atomic<bool> stopThread(false);
struct Building* build_type = make();
Mat img = imread("qdu_map.png", IMREAD_COLOR);
enum out_way{FOOT=1,BIKE=2,E_BIKE=3,CAR=10 };
void show_photo() {
    while (!stopThread) {
        imshow("map", img);
        waitKey(30);  // 非阻塞等待 30 毫秒
    }
    destroyAllWindows();  // 关闭窗口
}
int visited[51] = { 0 };
map<string, string>Curriculum;
int main() {
    
    cv::utils::logging::setLogLevel(cv::utils::logging::LOG_LEVEL_SILENT); //禁用opencv的日志
   
    thread imageThread(show_photo); 
    system("cls");
    //DFS(build_type,9,visited);
    Curriculum.insert(pair<string, string>("data_structure", "shenxing"));
    Curriculum.insert(pair<string, string>("os", "bozhi"));
    //Curriculum.insert(pair<string, string>("数据库", "bozhi"));
    Curriculum.insert(pair<string, string>("network", "shenxing"));
    Curriculum.insert(pair<string, string>("maogai", "bowen"));
    Curriculum.insert(pair<string, string>("Java", "shenxing"));
    Curriculum.insert(pair<string, string>("database", "bozhi"));

    cout << "the image size is 905*600" << endl;

    cout << "please enter your choice" << endl;
    cout << "choice 0: accurate inquiry" << endl << "choice 1: obscure inquiry" <<endl<<"choice 2: find the shortest path with two points" << endl <<"choice 3: find the shortage path with more points"<<endl;
    cout<<"choice 4: choose your vehicle and calculate time you need to get"<<endl;
    cout << "choice 5: choose order by curriculum" << endl;
    int choice;
    cin >> choice;
    switch (choice)
    {
    case 0: {
    start:
        int x = 0, y = 0;
        accurate_find(x, y, build_type);
        if (x == 0 && y == 0)
        {
            cout << "not found,please reinput the target building" << endl;
            goto start;
        }
        stopThread = true;
        imageThread.join();
        Point point(x, y);
        circle(img, point, 5, Scalar(0, 255, 0), -1);
        imshow("find", img);
        waitKey(0);
        break;
    }
    case 1: {
        vague_find(build_type);
        cout << "do you want to implement accurate find? 0-no,1-yes" << endl;
        int judgement=0;
        cin >> judgement;
        if (judgement) goto start;
        else
        {
            stopThread = true;
            imageThread.join();
        }
        break;
    }
    case 2:{
        int prev[51] = { 0 };
        double dist[51] = { 0 };
        cout << "enter you loacl building and enter the target building" << endl;
        string local_building, target_building;
        start1:
        cin >> local_building >> target_building;
        int local = -1, target = -1;
        for (int i = 0; i < 51; i++)
        {
            if (build_type[i].name == local_building)
            {
                target = i;
            }
            if (build_type[i].name == target_building)
            {
                 local = i;
            }
        }
        //cout << local << endl << target << endl;


        if (local == -1 || target == -1)
        {
            cout << "building not found, please enter again" << endl;
            goto start1;
        }
        Dijkstra(build_type, local, prev, dist);
       /* stopThread = true;
        imageThread.join();*/
        cout << "the shortest path is: " << endl;
        int temp = target;
        stopThread = true;
        imageThread.join();
        double x1, y1;
        x1 = build_type[temp].x;
        y1 = build_type[temp].y;
        Point point1;
        Point point2;
        while (temp!= -1)
        {
            Point point1(x1, y1);
            if (prev[temp] == -1) break;
            cout << build_type[temp].name << " -> ";
            temp = prev[temp];
            double x2, y2;
            x2 = build_type[temp].x;
            y2 = build_type[temp].y;
            Point point2(x2, y2);
            line(img, point1, point2, Scalar(0, 0, 255), 2);
            x1 = x2;
            y1 = y2;
        }
        circle(img, Point(build_type[target].x, build_type[target].y), 3, Scalar(0, 0, 0), -1);
        circle(img, Point(build_type[local].x, build_type[local].y), 3, Scalar(0, 0, 0), -1);
        cout << build_type[local].name << endl;
        cout << "the shortest distance is: " <<dist[target]<< endl;
        //line(img, point1, point2, (0, 255, 0), 2);
        imshow("path", img);
        waitKey(0);
        break;
    }
    case 4:
    case 3:
    {
        
        cout << "enter you loacl building and enter the processing building, and if you input \"finish\" it means over" << endl;
        string local_building, target_building;
        double distance = 0;
    start2:
        int Target, Local;
        int local = -1, target = -1;
        cin >> local_building >> target_building;
        for (int i = 0; i < 51; i++)
        {
            if (build_type[i].name == local_building)
            {
                target = i;
                Local = i;
            }
            if (build_type[i].name == target_building)
            {
                local = i;
            }
        }
        if (local == -1 || target == -1)
        {
            cout << "building not found, please enter again" << endl;
            goto start2;
        }
        cout << "the shortest path is: " << endl;
        while (target_building != "finished") {
            
            
            //cout << local << endl << target << endl;

            int prev[51] = { 0 };
            double dist[51] = { 0 };
            Dijkstra(build_type, local, prev, dist);
            /* stopThread = true;
             imageThread.join();*/
            distance += dist[target];
            int temp = target;
            double x1, y1;
            x1 = build_type[temp].x;
            y1 = build_type[temp].y;
            Point point1;
            Point point2;
            while (temp != -1)
            {
                Point point1(x1, y1);
                if (prev[temp] == -1) break;
                cout << build_type[temp].name << " -> ";
                temp = prev[temp];
                double x2, y2;
                x2 = build_type[temp].x;
                y2 = build_type[temp].y;
                Point point2(x2, y2);
                line(img, point1, point2, Scalar(0, 0, 255), 2);
                x1 = x2;
                y1 = y2;
            }
            cin >> target_building;
            if (target_building == "finished") Target = local;
            target = local;
            for (int i = 0; i < 51; i++)
            {
                if (build_type[i].name == target_building)
                {
                    local = i;
                    circle(img, Point(build_type[Local].x, build_type[Local].y), 3, Scalar(255, 0, 0), -1);
                }
            }
        }
        cout << build_type[local].name << endl;
        if (choice == 4)
        {
            cout << "chooce your way" << endl;
            cout << "1: foot" << endl << "2: bike " << endl << "3: e_bike" << endl << "4: car" << endl;
            int t;
            cin >> t;
            double time;
            switch (t) {
            case 1:
                time = distance / FOOT;
                break;
            case 2:
                time = distance / BIKE;
                break;
            case 3:
                time = distance / E_BIKE;
                break;
            case 4:
                time = distance / CAR;
                break;
            }
            cout << "the time you need is: " << (int)time/60<<"minutes and "<<time- ((int)time / 60*60 )<<" seconds" << endl;
        }
        stopThread = true;
        imageThread.join();
        circle(img, Point(build_type[Target].x, build_type[Target].y), 3, Scalar(0, 0, 0), -1);
        circle(img, Point(build_type[Local].x, build_type[Local].y), 3, Scalar(0, 0, 0), -1);
        
        cout << "the shortest distance is: " << distance << endl;
        //line(img, point1, point2, (0, 255, 0), 2);
        imshow("path", img);
        waitKey(0);
        break;
    }
    case 5: {
        start5:
        cout << "enter current curriculum and enter your next curriculum" << endl;
        string curriculum1, curriculum2;
        cin >> curriculum1 >> curriculum2;
        double distance = 0;
        map<string, string>::iterator it;
        it = Curriculum.find(curriculum1);
        curriculum1 = it->second;
        it = Curriculum.find(curriculum2);
        curriculum2 = it->second;
        cout << "the loacl is: " << curriculum1 << " and the target is: " << curriculum2 << endl;
        int prev[51] = { 0 };
        double dist[51] = { 0 };
        int loacl = -1, target = -1;
        for (int i = 0; i < 51; i++)
        {
            if (build_type[i].name == curriculum1)
            {
                target = i;
            }
            if (build_type[i].name == curriculum2)
            {
                loacl = i;
            }
        }
        if (loacl == -1 || target == -1)
        {
            cout << "ERROR,please enter again" << endl;
            goto start5;
        }
        Dijkstra(build_type, loacl, prev, dist);
        int temp = target;
        stopThread = true;
        imageThread.join();
        double x1, y1;
        x1 = build_type[temp].x;
        y1 = build_type[temp].y;
        Point point1;
        Point point2;
        while (temp != -1)
        {
            Point point1(x1, y1);
            if (prev[temp] == -1) break;
            cout << build_type[temp].name << " -> ";
            temp = prev[temp];
            double x2, y2;
            x2 = build_type[temp].x;
            y2 = build_type[temp].y;
            Point point2(x2, y2);
            line(img, point1, point2, Scalar(0, 0, 255), 2);
            x1 = x2;
            y1 = y2;
        }
        circle(img, Point(build_type[target].x, build_type[target].y), 3, Scalar(0, 0, 0), -1);
        circle(img, Point(build_type[loacl].x, build_type[loacl].y), 3, Scalar(0, 0, 0), -1);
        cout << build_type[loacl].name << endl;
        cout << "the shortest distance is: " << dist[target] << endl;
        //line(img, point1, point2, (0, 255, 0), 2);
        imshow("path", img);
        waitKey(0);
        break;
        
    }
    }
    delete[]build_type;
    return 0;
}

