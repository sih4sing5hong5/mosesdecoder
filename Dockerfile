FROM python:3.7-stretch
MAINTAINER sih4sing5hong5

RUN apt-get update -qq && \
  apt-get install -y \
    g++ \ 
    libxslt1-dev git subversion automake libtool zlib1g-dev libboost-all-dev libbz2-dev liblzma-dev libgoogle-perftools-dev libxmlrpc-c++.*-dev make \
    csh libc6-dev-i386 linux-libc-dev gcc-multilib

WORKDIR /usr/local/mosesserver
COPY . .

RUN ./bjam -j 2

