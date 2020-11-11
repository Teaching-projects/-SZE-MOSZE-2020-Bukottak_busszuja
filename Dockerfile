FROM ubuntu:20.04

ENV TZ=Europe/Budapest

RUN apt-get update && apt-get install --no-install-recommends -y software-properties-common && add-apt-repository ppa:ubuntu-toolchain-r/test && apt-get update

RUN apt-get install --no-install-recommends -y gcc g++ gcc-9 g++-9 doxygen graphviz valgrind cppcheck libgtest-dev make cmake git

RUN rm -rf /var/lib/apt/lists/*

RUN cd /usr/src/gtest && cmake . && make  && cp *.a /usr/lib && ln -s /usr/lib/libgtest.a /usr/local/lib/libgtest.a && ln -s /usr/lib/libgtest_main.a /usr/local/lib/libgtest_main.a