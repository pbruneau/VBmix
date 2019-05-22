##Installation from Docker

The Dockerfile at the repository root packages all dependency configuration. Simply run:

    git clone https://github.com/pbruneau/VBmix.git
    cd VBmix
    docker build
    docker run

Then connecting in the container with

    docker exec

allows running R interactive sessions and loading VBmix as indicated below.

##Manual Installation

    git clone https://github.com/pbruneau/VBmix.git
    R CMD build VBmix
    R CMD INSTALL VBmix_[VERSION_NUMBER].tar.gz

##Usage

In a R session, run:

    library(VBmix)
