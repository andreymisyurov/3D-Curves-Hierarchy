FROM ubuntu:20.04

RUN apt-get update && apt-get install -y \
    g++ \
    make \
    libgtest-dev \
    valgrind \
    cmake

WORKDIR /3D-Curves-Hierarchy

COPY . .

RUN make

CMD make tests && make leaks
