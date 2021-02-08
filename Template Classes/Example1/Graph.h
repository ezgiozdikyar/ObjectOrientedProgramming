#pragma once
#include<vector>
#include<iostream>
using namespace std;
template<typename T1, typename T2>
class Graph
{
private:
	T1 timeStep;
	vector<T2> data;
public:
	Graph();
	Graph(T1);
	Graph(T1, T2);
	void AddValue(T2);
	T2 getMax();
	T2 getMin();
	Graph<T1, T2> operator +=(const T2&);
};
#include "Graph.h"
template<typename T1, typename T2>
inline Graph<T1, T2>::Graph() :timeStep(0)
{
}
template<typename T1, typename T2>
inline Graph<T1, T2>::Graph(T1 timeStep) : timeStep(timeStep)
{

}

template<typename T1, typename T2>
Graph<T1, T2>::Graph(T1 time, T2 data) :timeStep(time), data(data)
{
}

template<typename T1, typename T2>
void Graph<T1, T2>::AddValue(T2 value)
{
	data.push_back(value);
}
template<typename T1, typename T2>
T2 Graph< T1, T2 >::getMax()
{
	T2 max = data[0];
	for (int i = 0; i < data.size(); i++)
		if (max < data[i])
			max = data[i];
	return max;
}
template<typename T1, typename T2>
T2 Graph<T1, T2>::getMin()
{
	T2 min = data[0];
	for (int i = 0; i < data.size(); i++)
		if (min > data[i])
			min = data[i];
	return min;
}
template<typename T1, typename T2>
Graph<T1, T2> Graph<T1, T2>::operator+=(const T2& value)
{
	data.push_back(value);
	return *this;
}