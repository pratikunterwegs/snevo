#include <vector>
#include <Rcpp.h>
#include <boost/geometry.hpp>
#include <boost/geometry/geometries/point.hpp>
#include <boost/geometry/index/rtree.hpp>
using namespace Rcpp;
#include "landscape.hpp"
#include <vector>
#include <algorithm>
#include <functional>

std::mt19937 rng;

void Resources::initResources() {
    // generate n central items
    std::vector<float> centreCoordX (nClusters);
    std::vector<float> centreCoordY (nClusters);

    std::uniform_real_distribution<float> item_ran_pos(0.0f, dSize);
    std::normal_distribution<float> item_cluster_spread(0.0f, clusterDispersal);

    for(size_t i = 0; i < static_cast<size_t>(nClusters); i++) {

        centreCoordX[i] = item_ran_pos(rng);
        centreCoordY[i] = item_ran_pos(rng);

        // also add to main set
        coordX[i] = centreCoordX[i];
        coordY[i] = centreCoordY[i];
    }

    // generate items around
    for(int i = nClusters; i < nItems; i++) {

        coordX[i] = (centreCoordX[(i % nClusters)] + item_cluster_spread(rng));
        coordY[i] = (centreCoordY[(i % nClusters)] + item_cluster_spread(rng));

        // wrap
        coordX[i] = fmod(dSize + coordX[i], dSize);
        coordY[i] = fmod(dSize + coordY[i], dSize);
    }

    // initialise rtree
    bgi::rtree< value, bgi::quadratic<16> > tmpRtree;
    for (int i = 0; i < nItems; ++i)
    {
        point p = point(coordX[i], coordY[i]);
        tmpRtree.insert(std::make_pair(p, i));
    }
    std::swap(rtree, tmpRtree);
    tmpRtree.clear();

    // set all to available
    available = std::vector<bool> (nItems, true);
}

void Resources::countAvailable() {
    nAvailable = 0;
    // counter set to max regeneration value on foraging
    for (size_t i = 0; i < static_cast<size_t>(nItems); i++){
        if(available[i]) {
            nAvailable ++;
        }
    }
}

/// function to export landscape as matrix
//' Returns a test landscape.
//'
//' @param nItems How many items.
//' @param landsize Size as a numeric (float).
//' @param nClusters How many clusters, an integer value.
//' @param clusterDispersal Dispersal of items around cluster centres.
//' @return A data frame of the evolved population traits.
// [[Rcpp::export]]
Rcpp::DataFrame get_test_landscape(
        const int nItems, const float landsize,
        const int nClusters, const float clusterDispersal) {
    Resources thisLandscape (nItems, landsize, nClusters, clusterDispersal);
    thisLandscape.initResources();

    return Rcpp::DataFrame::create(
                Rcpp::Named("x") = thisLandscape.coordX,
                Rcpp::Named("y") = thisLandscape.coordY
            );
}
