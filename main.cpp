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
    // auto f = [x]() // Using 'x' by itself and not a reference, uses it as a value
    auto f = [=]() mutable // Writing the Lambda function this way allows us to declare everything as a mutable value in the body
    {
        x++; // Now this works as the Lambda function has been declared mutable, however it works the same as creating another variable and storing the increment
             // as it still doesn't change the original value as it isn't a reference. You could change from [=] to [&] and modify the original value
        std::cout << x << std::endl;
    };

    // Calling the lambda function
    f();

    std::cin.get();
}
