FROM r-base:3.5.3

ADD . /repo
WORKDIR /repo

RUN apt-get update
RUN apt-get install libgsl-dev
RUN R CMD build . && R CMD INSTALL VBmix_0.3.2.tar.gz
