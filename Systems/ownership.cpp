#include <span>
#include <iostream>
#include <vector> 



void inspect(float values[64]){
    std::cout << sizeof(values) << "\n";
}


int main(){

    float values[64]{};
    
    std::cout << sizeof(values) << "\n"; // Would print 64 * 4 
    inspect(values); //after this it would print out 8, since the location of float values[64] - that is, being in the parameter - would make C++ look at it as a pointer
    
    return 0;
}

//We preserve size information by using std::span

void inspect(std::span<const float> values) {
    std::cout << values.size_bytes() << '\n';
}


// Life time vs Ownership

//By including span in the parameter, C++ treats it as a pointer pointing to weights[0]
void other(std::span<const float> weights){
    weights[0] *= 10;
}

//The lifespan is controlled by main - the vector object owns allocation
int main(){
    std::vector<float> weights {1.0f, 2.0f, 3.0f};
    other(weigts)
    std::cout << weights[0] << '\n';

}



//Lifetime Trap

int main(){
    std::vector<float> weights{1.0f, 2.0f, 3.0f};
    std::span<float> view = weights;

    weights.reserve(weights.capacity() + 1);
    std::cout << view[0] << '\n';
}

//This would give us undefined behavior - the vector's address would change after .reserve() but the address of span would still point to the same one


