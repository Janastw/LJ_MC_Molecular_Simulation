#include <random> // for random numbers
#include <chrono> // for generating the seed

// A Global! Probably shouldn't be used in real code
std::default_random_engine re;

/*! Generate a random double within a given range */
double random_double(double lower_bound, double upper_bound)
{
   std::uniform_real_distribution<double> dist(lower_bound, upper_bound);
   return dist(re);
}

/*! Generate a random integer within a given range
    The generated integer will be on the range [a,b)
*/
int random_integer(int lower_bound, int upper_bound)
{           
   //dist will return [a,b] but we want [a,b)
   std::uniform_int_distribution<int> dist(lower_bound, upper_bound-1);
   return dist(re);
}  

int main(void)
{
    // Initialize random number generation based on time
    re.seed(std::chrono::system_clock::now().time_since_epoch().count());

    /*
      Other code here
    */
}