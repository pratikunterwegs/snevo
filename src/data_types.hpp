#ifndef DATA_TYPES_H
#define DATA_TYPES_H
/// data types and related functions
#include <vector>
#include <random>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "agents.hpp"
#include "network.hpp"

// define a struct holding a vector of data frames which holds generation wise data
struct genData {
public:
    std::vector<std::vector<float> > genEnergyVec;
    std::vector<std::vector<float> > genCoefFoodVec;
    std::vector<std::vector<float> > genCoefNbrsVec;
    // std::vector<std::vector<int> > genAssocVec;
    // std::vector<std::vector<int> > genDegreeVec;
    std::vector<int> gens;

    void updateGenData (Population &pop, const int gen);
    Rcpp::List getGenData ();
};

struct moveData {
public:
    std::vector<std::vector<int> > id;
    std::vector<std::vector<float> > coordX;
    std::vector<std::vector<float> > coordY;
    std::vector<std::vector<float> > energy;
    std::vector<int> timestep;

    void updateMoveData (Population &pop, const int timestep);
    Rcpp::List getMoveData ();
};

#endif  //
