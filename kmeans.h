#ifndef KMEANS_H
#define KMEANS_H
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
typedef struct datacluster datacluster;
typedef struct datapoint datapoint;
struct datapoint
{
        float x;
        float y;
	datacluster *cluster;
};
struct datacluster
{
        int idx;
        char *name;
        datapoint mean;
};
//kmeans.c
float eStep(datapoint *points, datacluster clusters[], int npoints, int nclusters);
void mStep(datapoint *points, datacluster clusters[], int npoints, int nclusters);
void printOutput(datapoint points[], int npoints, float error);
//points.c
float eucDistance(datapoint A, datapoint B);
void printpoints(datapoint points[],int npoints);
void readPointsFromFile(char* filename, datapoint points[]);
//clusters.c
void printClusters(datacluster cluster[], int nclusters);
void initClusters(datacluster *clusters);
#endif
