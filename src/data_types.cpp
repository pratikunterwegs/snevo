
#include "data_types.hpp"

// function to update move
void moveData::updateMoveData (Population &pop, const int timestep_) {
    // get pop data
    std::vector<int> idVec (pop.nAgents);
    for (size_t i = 0; i < pop.nAgents; i++) {
        idVec[i] = i;
    }

    id.push_back(idVec);
    coordX.push_back(pop.coordX);
    coordY.push_back(pop.coordY);
    energy.push_back(pop.energy);
    timestep.push_back(timestep_);
}

// function to return move data as an rcpp list
Rcpp::List moveData::getMoveData() {
    Rcpp::List moveDataList (timestep.size());
    for (size_t i = 0; i < timestep.size(); i++)
    {
        moveDataList[i] = DataFrame::create(
            Named("id") = id[i],
            Named("energy") = energy[i],
            Named("x") = coordX[i],
            Named("Y") = coordY[i]
        );
    }
    List dataToReturn = List::create(
        Named("move_data") = moveDataList,
        Named("timestep") = timestep
    );

    return dataToReturn;
}

// function to update gendata
void genData::updateGenData (Population &pop, const int gen_) {
    // get pop data
    genEnergyVec.push_back(pop.energy);
    genCoefFoodVec.push_back(pop.coef_food);
    genCoefNbrsVec.push_back(pop.coef_nbrs);
    // genAssocVec.push_back(pop.associations);
    // genDegreeVec.push_back(pop.degree);
    gens.push_back(gen_);
}

// function to return gen data as an rcpp list
Rcpp::List genData::getGenData() {
    Rcpp::List genDataList (gens.size());
    for (size_t i = 0; i < gens.size(); i++)
    {
        genDataList[i] = DataFrame::create(
            Named("energy") = genEnergyVec[i],
            Named("coef_food") = genCoefFoodVec[i],
            Named("coef_nbrs") = genCoefNbrsVec[i]
            // Named("associations") = genAssocVec[i],
            // Named("degree") = genDegreeVec[i]
        );
    }
    List dataToReturn = List::create(
        Named("pop_data") = genDataList,
        Named("gens") = gens
    );

    return dataToReturn;
}
