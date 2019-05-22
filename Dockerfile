FROM r-base:3.5.3

ADD . /repo
WORKDIR /repo

apt-get update
apt-get install libgsl-dev
git clone https://github.com/pbruneau/VBmix.git
R CMD build VBmix
R CMD INSTALL VBmix_0.3.2.tar.gz

