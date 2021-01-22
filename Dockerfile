#FROM r-base:3.6.3
FROM r-base:4.0.3

ADD . /repo
WORKDIR /repo

RUN apt-get update
RUN apt-get install -y libgsl-dev
RUN ./rpkginstall pixmap
RUN ./rpkginstall mnormt
RUN R CMD build . && R CMD INSTALL VBmix_0.3.2.tar.gz

WORKDIR /
CMD ["bash"]
