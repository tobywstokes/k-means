#include "kmeans.h"
int main()
{
	int npoints = 10000, nclusters = 5;
	float error[2] = {0}, errorchange = 1;
	datapoint points[npoints];
	datacluster clusters[nclusters];
	initClusters(clusters);
	readPointsFromFile("input.csv",points);
	while(errorchange > 0)
	{
		error[0] = eStep(points, clusters, npoints, nclusters);
		mStep(points, clusters, npoints, nclusters);
		errorchange = abs(error[1] - error[0]);
		error[1] = error[0];
	}
	printOutput(points, npoints, error[0]);
}

float eStep(datapoint *points, datacluster *clusters,int npoints, int nclusters)
{
	float distance,shortestDistance, error = 0;
	int i,j, shortestIdx;
	for (i = 0; i < npoints; i++)
	{
		shortestDistance = 100;
		for(j = 0; j < nclusters; j++)
		{
			distance = eucDistance(points[i], clusters[j].mean);
			if (distance < shortestDistance)
			{
				shortestDistance = distance;
				shortestIdx = j;
			}
		}
		error = error + shortestDistance;
		points[i].cluster = &clusters[shortestIdx];
	}
	return error;
}

void mStep(datapoint *points, datacluster clusters[], int npoints, int nclusters)
{
	datapoint sum[5] = {{0,0,NULL}};
	int count[5]={0}, i;
	for (i = 0; i < npoints; i++) // Sum both dimensions for each cluster and count members
	{
		sum[points[i].cluster->idx].x = sum[points[i].cluster->idx].x + points[i].x;
		sum[points[i].cluster->idx].y = sum[points[i].cluster->idx].y + points[i].y;
		count[points[i].cluster->idx] = count[points[i].cluster->idx] + 1;
	}
	for (i = 0; i < nclusters; i++) // Calculate each cluster's new mean
	{
		clusters[i].mean.x = sum[i].x / count[i];
		clusters[i].mean.y = sum[i].y / count[i];
	}
}

void printOutput(datapoint points[], int npoints, float error)
{
	int i;
	printf("Error = %.3f\n",error);
	for(i = 0; i < npoints; i++)
	{
		printf("%s\n",points[i].cluster->name);
	}

}

