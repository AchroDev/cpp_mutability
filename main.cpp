#include <iostream>

// Mutability!

// Example Entity class
class Entity
{
    // Single private member 'm_Name'
private:
    std::string m_Name;
    int m_DebugCount = 0; // We don't wont to move this outside of the class as it is messy and makes it harder to track
    // Public section
public:
    // Simple getter that gets and returns the name, we are enforcing const here so that we can use the
    const std::string &GetName() // Removed const
    {
        m_DebugCount++; // With the const removed, we can now increment the debug count
        return m_Name;
    }
};

int main()
{
    const Entity e;
    e.GetName(); // OOPS, looks like we broke this though....

    std::cin.get();
}
