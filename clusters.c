#include "kmeans.h"
void printClusters(datacluster clusters[],int nclusters)
{
	int i;
	for (i=0;i < nclusters; i++)
	{
		printf("%s = (%1.3f,%1.3f) ", clusters[i].name, clusters[i].mean.x, clusters[i].mean.y);
	}
	printf("\n");
}

void initClusters(datacluster *clusters)
{
	clusters[0].idx = 0;
	clusters[0].name = "Adam";
	clusters[0].mean.x = 0.357;
	clusters[0].mean.y = -0.253;

	clusters[1].idx = 1;
    clusters[1].name = "Bob";
    clusters[1].mean.x = -0.055;
    clusters[1].mean.y = 4.392;

	clusters[2].idx = 2;
    clusters[2].name = "Charley";
    clusters[2].mean.x = 2.674;
    clusters[2].mean.y = -0.001;

	clusters[3].idx = 3;
    clusters[3].name = "David";
    clusters[3].mean.x = 1.044;
    clusters[3].mean.y = -1.251;

    clusters[4].idx = 4;
    clusters[4].name = "Edward";
    clusters[4].mean.x = -1.495;
    clusters[4].mean.y = -0.090;
}
