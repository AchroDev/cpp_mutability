#include <iostream>

// Mutability!

// Example Entity class
class Entity
{
    // Single private member 'm_Name'
private:
    std::string m_Name;
    mutable int m_DebugCount = 0; // Now declared as mutable
    // Public section
public:
    // Simple getter that gets and returns the name, we are enforcing const here so that we can use the
    const std::string &GetName() const // Restored const
    {
        m_DebugCount++; // With the const restored and the int 'm_DebugCount' declared mutable, we can increase while keeping the const promise.
        return m_Name;
    }
};

int main()
{
    const Entity e;
    e.GetName(); // This is also fixed now because the const was restored

    int x = 0;

    // Example Lambda function, essentially a quick "throw-away" function
    auto f = [&x]() // If we use 'x' we must define a catcher method in the brackets, &x provides a reference
    {
        std::cout << x << std::endl; // Now using 'x' instead of the char array
    };

    // Calling the lambda function
    f();

    std::cin.get();
}
