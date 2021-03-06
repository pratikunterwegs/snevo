args = commandArgs(TRUE)

message(getwd())

param_file = args[1]

row_n = as.numeric(args[2])

message(
  paste("which file = ", param_file)
)

message(
  paste("which row = ", row_n)
)

params = read.csv(param_file)

library(snevo)

# run simulation
data_evolved_pop = do_simulation(
  popsize = params$popsize[row_n],
  genmax = params$genmax[row_n], 
  tmax = params$tmax[row_n],
  nFood = params$nFood[row_n],
  foodClusters = params$foodClusters[row_n], 
  clusterDispersal = params$clusterDispersal[row_n],
  landsize = params$landsize[row_n],
  collective = params$collective[row_n],
  competitionCost = params$collective[row_n],
  nScenes = params$nScenes[row_n]
)

# get params as named vector
these_params = unlist(params[row_n,])

# append list of params
data_evolved_pop = append(
  data_evolved_pop,
  these_params
)

# name of rdata file
output_file = Reduce(
  paste,
  mapply(
    function(p, np) {
      paste(np, p, sep = "_")
    }, these_params, names(these_params)
  )
)
output_file = glue::glue(
  'data/output/{output_file}.Rdata'
)

# save
save(
  data_evolved_pop,
  file = output_file
)
