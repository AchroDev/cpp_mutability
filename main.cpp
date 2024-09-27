#include <iostream>

// Mutability!

// Example Entity class
class Entity
{
    // Single private member 'm_Name'
private:
    std::string m_Name;
    int m_DebugCount = 0;
    // Public section
public:
    // Simple getter that gets and returns the name, we are enforcing const here so that we can use the
    const std::string &GetName() const // The const here marks the method as a constant
    {
        m_DebugCount++; // Here is where the issue comes in, for debugging purposes we would like to know how many times this method gets called
                        // since the method is a const, we cannot change the data like this.
        return m_Name;
    }
};

int main()
{
    const Entity e;
    e.GetName(); // Since the method is marked as a constant we can access the method here

    std::cin.get();
}
