#pragma once
#ifndef FUNCTION_H
#define FUNCTION_H
#include"building.h"
#include<string>
void accurate_find(int& x, int& y,struct Building * build_type);
void vague_find(struct Building* build_type);
bool judge(std::string name1, std::string name2);
void DFS(struct Building* build_type, int index, int* visited);
void Dijkstra(struct Building* build_type, int vs, int* pre, double* dist);

#endif