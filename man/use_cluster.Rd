% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/fun_use_cluster.R
\name{use_cluster}
\alias{use_cluster}
\title{Run snevo and the cluster.}
\usage{
use_cluster(
  ssh_con = "some_server",
  password = "your_password",
  script = "which_script.R",
  template_job = "some_template.sh",
  parameter_file = "which_parameters.csv"
)
}
\arguments{
\item{ssh_con}{SSH connection.}

\item{password}{Password.}

\item{script}{Which R script to run.}

\item{template_job}{Which shell script to use as a template.}

\item{parameter_file}{Where to get parameters.}
}
\value{
Runs a job which makes more jobs.
}
\description{
Run snevo and the cluster.
}
