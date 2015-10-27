//
//  Kmeans.h
//  pa2-ucd
//
//  Created by Tisha Konz on 10/9/15.
//  Copyright (c) 2015 Tisha Konz. All rights reserved.
//

#ifndef __pa2_ucd__Kmeans__
#define __pa2_ucd__Kmeans__

#include <stdio.h>
#include <iostream>
#include <fstream>
#include "Cluster.h"
#include "Point.h"

namespace Clustering
{
    typedef Cluster *ClusterPtr;
    class Kmeans
    {
    private:
        int __k;
        double oldScore, newScore;
        double scoreDiff;
        static double SCORE_DIFF_THRESHOLD;
        int __dimensionality;
        Cluster point_space;
        ClusterPtr vec = new Cluster(__dimensionality);
        
    public:
        Kmeans(int k, int dim) :
        __k(k),
        __dimensionality(dim),
        // initial cluster called point_space initialized in Kmeans constructor
        point_space(__dimensionality)
        {
            ifstream csv("points.txt");
            
            while (csv.is_open() && !csv.eof())
            {
                csv >> point_space;
                cout << "Point: " << point_space << endl;
                
            }
            cout << "Point: " << point_space << endl;
            csv.close();
            
        };
        
        double computeClusteringScore();
        
        void kMeansAlgorithm();
        
        
    };
    
    
}

#endif /* defined(__pa2_ucd__Kmeans__) */