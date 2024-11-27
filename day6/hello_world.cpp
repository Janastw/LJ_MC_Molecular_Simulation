#include <iostream>

void say_hello(std::string name, int count)
{
    
    std::cout << count << ".)";

    if(name == "Dr. Pritchard")
    {
        std::cout << "Hello, " << name << " (from MolSSI)" << std::endl;
    }
    else if (name == "Dr. Nash")
    {
        std::cout << "Hello, " << name << " (from MolSSI)" << std::endl;
    }
    else
    {
        std::cout << "Hello, " << name << " (from parts unknown)" << std::endl;
    }
}

int main(void)
{
    //std::cout << "Hello, world!" << std::endl;
    // python: for i in range(1):

    // i++ => i = i + 1;
    

    for (int i = 0; i < 10; i++)
    {
        say_hello("Dr. Pritchard", i);

    }

    say_hello("Thomas", 2);
    say_hello("Dr. Nash", 1);

    return 0;
}