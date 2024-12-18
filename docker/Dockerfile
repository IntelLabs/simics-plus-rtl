FROM docker.io/ubuntu:24.04
ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update \
 && apt-get -y install --no-install-recommends curl make openjdk-21-jdk g++ \
                          python3 verilator libgtk2.0-0 libxpm4 libxxf86vm1 \
 && apt-get clean \
 && rm -rf /var/lib/apt/lists/*

RUN mkdir -p -v /home && chown -R ubuntu:ubuntu /home
WORKDIR /home
USER ubuntu

# firtool from MLIR/circt (https://github.com/llvm/circt)
RUN curl -L -O https://github.com/llvm/circt/releases/download/firtool-1.62.0/firrtl-bin-linux-x64.tar.gz \
 && tar -xzf firrtl-bin-linux-x64.tar.gz \
 && rm -rf firrtl-bin-linux-x64.tar.gz

# sbt from https://github.com/sbt/sbt/
RUN curl -L -O https://github.com/sbt/sbt/releases/download/v1.9.9/sbt-1.9.9.tgz \
 && tar -xzf sbt-1.9.9.tgz \
 && rm -rf sbt-1.9.9.tgz

ENV CHISEL_FIRTOOL_PATH=/home/firtool-1.62.0/bin
ENV LC_ALL=C
ENV PATH=/home/sbt/bin:$PATH
