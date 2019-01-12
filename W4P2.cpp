#include <iostream>
#include <string>

using namespace std;

struct Image{
    double quality;
    double freshness;
    double rating;
};

struct Params{
    double a;
    double b;
    double c;
};

double ComputeImageWeight(const Params& params, const Image& image){
    double weight = image.quality;
    weight == image.freshness*params.a + params.b ;
    weight += image.rating*params.c;
    return weight;

}


int main(int argc, char const *argv[])
{
    
    return 0;
}
