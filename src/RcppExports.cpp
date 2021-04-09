// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// get_test_landscape
Rcpp::DataFrame get_test_landscape(const int nItems, const double landsize, const int nClusters, const double clusterDispersal);
RcppExport SEXP _snevo_get_test_landscape(SEXP nItemsSEXP, SEXP landsizeSEXP, SEXP nClustersSEXP, SEXP clusterDispersalSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const int >::type nItems(nItemsSEXP);
    Rcpp::traits::input_parameter< const double >::type landsize(landsizeSEXP);
    Rcpp::traits::input_parameter< const int >::type nClusters(nClustersSEXP);
    Rcpp::traits::input_parameter< const double >::type clusterDispersal(clusterDispersalSEXP);
    rcpp_result_gen = Rcpp::wrap(get_test_landscape(nItems, landsize, nClusters, clusterDispersal));
    return rcpp_result_gen;
END_RCPP
}
// do_simulation
Rcpp::List do_simulation(int popsize, int genmax, int tmax, int nFood, int foodClusters, double clusterDispersal, double landsize);
RcppExport SEXP _snevo_do_simulation(SEXP popsizeSEXP, SEXP genmaxSEXP, SEXP tmaxSEXP, SEXP nFoodSEXP, SEXP foodClustersSEXP, SEXP clusterDispersalSEXP, SEXP landsizeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type popsize(popsizeSEXP);
    Rcpp::traits::input_parameter< int >::type genmax(genmaxSEXP);
    Rcpp::traits::input_parameter< int >::type tmax(tmaxSEXP);
    Rcpp::traits::input_parameter< int >::type nFood(nFoodSEXP);
    Rcpp::traits::input_parameter< int >::type foodClusters(foodClustersSEXP);
    Rcpp::traits::input_parameter< double >::type clusterDispersal(clusterDispersalSEXP);
    Rcpp::traits::input_parameter< double >::type landsize(landsizeSEXP);
    rcpp_result_gen = Rcpp::wrap(do_simulation(popsize, genmax, tmax, nFood, foodClusters, clusterDispersal, landsize));
    return rcpp_result_gen;
END_RCPP
}
// export_pop
DataFrame export_pop(int popsize);
RcppExport SEXP _snevo_export_pop(SEXP popsizeSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< int >::type popsize(popsizeSEXP);
    rcpp_result_gen = Rcpp::wrap(export_pop(popsize));
    return rcpp_result_gen;
END_RCPP
}

static const R_CallMethodDef CallEntries[] = {
    {"_snevo_get_test_landscape", (DL_FUNC) &_snevo_get_test_landscape, 4},
    {"_snevo_do_simulation", (DL_FUNC) &_snevo_do_simulation, 7},
    {"_snevo_export_pop", (DL_FUNC) &_snevo_export_pop, 1},
    {NULL, NULL, 0}
};

RcppExport void R_init_snevo(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
