#ifndef Writer_hpp
#define Writer_hpp

#include <chrono>
#include <stdio.h>
#include <memory>
#include <iostream>
#include <string>
#include <mpi.h>
#include <hdf5.h>
#include <sys/stat.h>
#include <unistd.h>

#include "../grid/GridManager.hpp"
#include "../input/Loader.hpp"
#include "../physics/pusher/Pusher.hpp"


class Writer
{
private:
    std::string outputDir;
    std::string fileNamePattern;

    std::unique_ptr<Logger> logger;
    std::shared_ptr<Loader> loader;
    std::shared_ptr<GridManager> gridMgr;
    std::shared_ptr<Pusher> pusher;
    

    void writeData(std::string datasetName, const double* data, int[3], int, int);
    void writeParallel(hid_t, hid_t, hid_t, std::string  , const double* , int[3]);
    void writeDetectorVar(hid_t, hid_t, hid_t, std::string  , const double* , int[3]);
    
    void writeTrackedParticles(int);

public:
   Writer(std::shared_ptr<Loader>, std::shared_ptr<GridManager>, std::shared_ptr<Pusher>);
   void write(int);
};
#endif /* Writer_hpp */
