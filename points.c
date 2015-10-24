 #include "kmeans.h"
void printpoints(datapoint points[], int npoints)
{
	int i ;
	for(i = 0; i<npoints; i++)
	{
		if (points[i].cluster == NULL)
		{
			printf("Point %d, x = %f , y = %f\n",i, points[i].x, points[i].y);
		}
		else
		{
			printf("Point %d, x = %f , y = %f, Cluster %s\n", i, points[i].x, points[i].y, points[i].cluster->name);
		}
	}
}

void readPointsFromFile(char* filename, datapoint *points)
{
	FILE *fp;
	int c = 0;
	fp = fopen(filename,"r");
	if (fp == NULL)
	{
		fprintf(stderr,"Could not open file \n");
	}
	while (fscanf(fp,"%f,%f\n",&points[c].x,&points[c].y)!=EOF)
	{
		c++;
	}
	fclose(fp);
}

float eucDistance(datapoint A, datapoint B)
{
        //Returns the 2D euclidean distance between two points
        float xdist,ydist,eucdist;
        xdist = A.x - B.x;
        ydist = A.y - B.y;
        eucdist = sqrt( pow(xdist,2) + pow(ydist,2) );
        return eucdist;
}

