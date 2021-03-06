## Installation with Docker (preferred)

The Dockerfile at the repository root packages all dependency configuration. Simply run:

    git clone https://github.com/pbruneau/VBmix.git
    docker build -t r_vbmix VBmix
    docker run -d --name vbmix_container -t r_vbmix

Then connecting in the container with

    docker exec -it vbmix_container bash

allows running R interactive sessions and loading VBmix as indicated below.

## Manual Installation

    git clone https://github.com/pbruneau/VBmix.git
    R CMD build VBmix
    R CMD INSTALL VBmix_[VERSION_NUMBER].tar.gz

## Usage

In a R session, run:

    library(VBmix)
