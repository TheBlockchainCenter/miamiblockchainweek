FROM gcc:latest
COPY . /usr/src/cpp
WORKDIR /usr/src/cpp
RUN g++ -o Test BlockChain.cpp
CMD [ "./Test" ]