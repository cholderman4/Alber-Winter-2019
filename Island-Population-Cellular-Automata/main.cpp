//#include <boost>
#include <cmath>        // exp()
#include <algorithm>    // transform()
#include <numeric>      // accumulate(), reduce()?
#include <vector>
#include <random>
#include <iostream>


struct checkDeath {

    checkDeath() {}

    bool operator() (int s) {
        /* double mean = 4.0f;
        double p_death = 1-exp(-(1/mean) * age); */

        // Simple death probability.
        double p_death = 0.9;

        // Initialize random number stuff.
        std::random_device rd;  //Will be used to obtain a seed for the random number engine
        std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
        std::uniform_real_distribution<> dis(0.0, 1.0);
        

        if (dis(gen) < p_death) {
            return 1;
        }
        else {
            return 0;
        }

        // Simple death conditions.
        // All five year olds must die! :(
        //return age > 4;
    }

};

template<typename T>
void updateDeath(std::vector<T>& v) {
    auto result = std::remove_if(v.begin(), v.end(), checkDeath());
    v.erase(result, v.end());

}

/*void advanceAge(std::vector<unsigned>& age) {

    std::for_each(age.begin(), age.end(), [](double& d) { d+=1;});

} */

template<typename T>
void recruitToA(std::vector<T>& v) {

    // Wrap the vector around into a circle.
    std::vector<T> circleSpecies(v.size()+2);
    std::copy(v.end()-1, v.end(), circleSpecies.begin());
    std::copy(v.begin(), v.end(), circleSpecies.begin()+1);
    std::copy(v.begin(), v.begin()+1, circleSpecies.end()-1);

    
    // This represents B surrounded by two A's, which leads to B converting to A.
    std::vector<T> seq{1, 0, 1};
    //std::cout << "Testing recruitment to A: " << std::endl;
    for(std::vector<bool>::iterator it = circleSpecies.begin()+1; it != circleSpecies.end()-1; ++it) {

        // Checking that the conditions are met to recruit a B to A.
        if(std::equal(seq.begin(), seq.end(), it-1)) {
            *it = 1;
        //    std::cout << 8 << "      " << "TRUE" << std::endl;
        }
        else {
        //    std::cout << *it << "      " << "" << std::endl;
        }
        
    }

    std::copy(circleSpecies.begin()+1, circleSpecies.end()-1, v.begin());    

}

template <typename T>
void birthCycleB(std::vector<T>& v, std::vector<int>& age) { 
    std::vector<T> circSpecies(v.size()+1);
    std::copy(v.begin(), v.end(), circSpecies.begin());
    std::copy(v.begin(), v.begin()+1, circSpecies.end()-1);
    
    
    std::vector<T> seq{0, 0};
    //std::cout << "Testing births from B: " << std::endl;
    for(std::vector<bool>::iterator it = circSpecies.begin(); it != circSpecies.end()-1; ++it) {

        if(std::equal(seq.begin(), seq.end(), it)) {
        //    std::cout << *it << "      " << "TRUE" << std::endl;
        //    std::cout << 8 << "      " << "BABY" << std::endl;

            it = circSpecies.insert(it+1, 0);
        }
        else {
        //    std::cout << *it << "      " << "" << std::endl;
        }
    }

    // Save changes in birth cycle to original vector.
    v.resize(circSpecies.size()-1);
    std::copy(circSpecies.begin(), circSpecies.end()-1, v.begin());

}

void initializePopulation(std::vector<bool>& species, double p_A) {
    
    // Initialize random number stuff.
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(0.0, 1.0);
    
    
    // Initial assignment of population to be A(1) or B(0).
    std::cout << "Testing initial population assignment: " << std::endl;
    for (auto s : species) {
        if (dis(gen) < p_A) {
            s = 1;
        }
        // Print out the original vector for testing.
        std::cout << s << std::endl;

        // Totaling the amount of A's to check the probability.
    }
    // Check average value of A's. Should be ~0.5
    // Starting values of species.
    double total = std::accumulate(species.begin(), species.end(), 0.0);
        std::cout << "POP_SIZE: " << species.size() << "  ";
        std::cout << "A's: " 
            << total/(double)species.size() << std::endl;
}

void runTest() {
    //************************************************************************
    //Testing Stuff

    /* std::vector<int> seq{2, 3};
    std::vector<int> v(20);
    std::iota(v.begin(), v.end(), 0);
    //std::vector<int> v2{1, 2, 3, 4, 5, 1, 2, 3, 4, 5};

    //std::transform(v.begin(), v.end(), willDie.begin(), checkDeath());
    std::cout << "Testing deleting from death: " << std::endl;
    for(std::vector<int>::iterator it = v.begin(); it < v.end(); ++it) {

        if(std::equal(seq.begin(), seq.end(), it)) {
            std::cout << *it << "      " << "DIE!!!!" << std::endl;
            v2.erase(it);
            it = v.erase(it)-1;
        }
        else {
            std::cout << *it << "      " << "" << std::endl;
        }
    }

    std::cout << "Testing death check: " << std::endl;
    for (auto i = 0; i < willDie.size(); ++i) {
        std::cout << v[i] << "   " << willDie[i] << std::endl;
    }

    calculateDeath(v);

    std::cout << "Testing vector after death: " << std::endl;
    for (auto s : v) {
        std::cout << s << std::endl;
    } */
    //***********************************************************************
}

void calculatePopRatios(std::vector<bool>& species) {
     double total = std::accumulate(species.begin(), species.end(), 0.0);
        std::cout << "POP_SIZE: " << species.size() << "  ";
        std::cout << "A's: " 
            << total/(double)species.size() << std::endl;
}

int main() {

    unsigned POP_SIZE = 20;
    std::vector<bool> species(POP_SIZE, 0);
    //std::vector<unsigned> age(POP_SIZE, 0);
    
    double p_A = 0.5;

    initializePopulation(species, p_A);

    // This is the actual simulation. Currently running for 10 time steps.
    for(int i=0; i<10; ++i) {
        
        recruitToA(species);

        birthCycleB(species);

        // This is just for testing to see what's happening with the population.
        calculatePopRatios(species);

        updateDeath(species);

        //Not ready to implement age yet.
        //advanceAge(age);        
    } 

        
    // Testing stupid stuff.
    //runTest();

    return 0;
}