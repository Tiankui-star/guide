#include"function.h"
#include<iostream>
#include<string>
#include"building.h"
void accurate_find(int& x, int& y,struct Building* build_type)
{
    std::string name;
    std::cout << "Enter the name of the building to be queried" << std::endl;
    std::cin >> name;
    inquiry(name, build_type, x, y);
}
void vague_find(struct Building* build_type)
{
    std::string name;
    std::cout << "Enter the building that you want" << std::endl;
    std::cin >> name;
    for (int i = 0; i < 22; i++)
    {
        if (judge(name, build_type[i].name))
        {
            std::cout << "the building name is:"<<build_type[i].name << "  Row coordinates:" << build_type[i].x << "  Column coordinates:" << build_type[i].y << std::endl;
        }
    }

}
bool judge(std::string name1, std::string name2)
{
    for (int i = 0; i < name1.size(); i++)
    {
        if (name1[i] != name2[i]) return false;
    }
    return true;
}
void DFS(struct Building* build_type,int index,int *visited)
{
    visited[index] = 1;
    std::cout << "building " << build_type[index].name << " visited" << std::endl;
    struct Building* temp = build_type[index].next;
    while (temp != NULL)
    {
        if (visited[temp->index] == 0)
        {
            DFS(build_type,temp->index,visited);
        }
        temp = temp->next;
    }
}

void Dijkstra(struct Building* build_type, int vs, int* pre, double* dist)
{
    int k = 0;
    double min;
    double tmp;
    int flag[51] = { 0 };
    for (int i = 0; i < 51; i++)
    {
        pre[i] = -1;
        dist[i] = 100000;
    }
    flag[vs] = 1;
    dist[vs] = 0;
    struct Building* temp = build_type[vs].next;
    while (temp != NULL)
    {
        if (flag[temp->index] == 0)
        {
            dist[temp->index] = temp->distance;
            pre[temp->index] = vs;
           // std::cout << "index" <<temp->index<< std::endl;
        }
        temp = temp->next;
    }
    for (int i = 0; i < 51; i++)
    {
        min = 100000;
        for (int j = 0; j < 51; j++)
        {
            if (flag[j] == 0 && dist[j] < min)
            {
                min = dist[j];
                k = j;
                //std::cout <<"k: " << k << std::endl;
            }
        }
        flag[k] = 1;
        temp = build_type[k].next;
        int count = 0;
        while (temp != NULL)
        {
            
            if (flag[temp->index] == 0)
            {
                //std::cout << "k:" << k << std::endl;
                tmp = dist[k] + temp->distance;
                //std::cout << "tmp:" << dist[k] << std::endl;
                if (flag[temp->index] == 0 && tmp < dist[temp->index])
                {
                    dist[temp->index] = tmp;
                    pre[temp->index] = k;
                }
            }
            temp = temp->next;
            count++;
            //std::cout << "count" << count << std::endl;
        }
    }
}