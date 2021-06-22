#ifndef BoundaryManager_hpp
#define BoundaryManager_hpp
#include <stdio.h>
#include <vector>
#include <map>
#include <cmath>
#include <memory>
#include <chrono>


#include <mpi.h>
#include "../../misc/Logger.hpp"
#include "../../misc/Misc.hpp"
#include "../../input/Loader.hpp"
#include "../../particles/Particle.hpp"

#include "../../common/variables/VectorVar.hpp"


#define OUT  1
#define IN  -1

// need to reserve memory for outcoming from domain particles
int const NUM_OF_LEAVING_PACTICLES  = 1000000;
// need to reserve memory for incoming in domain particles
int const EXPECTED_NUM_OF_PARTICLES = 1000000;

class BoundaryManager{
    
private:
    int finished = 0;
    std::unique_ptr<Logger> logger;
    std::shared_ptr<Loader> loader;
    
    std::vector<double> leavingParticles;
    std::map<int, int> domain2send;
    
    void initialize();
    int  applyOutflowBC(Particle*);
    
    
public:
    
    BoundaryManager(std::shared_ptr<Loader>);
    
    int isPtclOutOfDomain(double[3]);
    void reset();
    std::vector<double> getLeavingParticlesIdxs();
    void storeParticle(int, double[3]);
    void applyBC(Particle**, std::vector<std::shared_ptr<Particle>> &);
    int getNumberOfFinished();
    
};
#endif /* BoundaryManager_hpp */
