// vehicle.cpp
/*
 * Author: Josiah Andrews
 * Created: 5/3/2024
 * Description: Submarine driving simulator
 */

#include <iostream>

// base class
class Submarine
{
protected:
    std::string m_name;
    int m_depth;
    bool m_submerged = false;
    int m_max_depth;

public:
    bool still_diving = true;

    Submarine(std::string name, int depth, int max_depth)
    {
        m_name = name;
        m_max_depth = max_depth;
        m_depth = depth;
    }

    void submerge()
    {
        if (!m_submerged)
        {
            m_submerged = true;
            std::cout << "Your submarine is now submerged" << std::endl;
        }
        else
        {
            std::cout << "Your submarine is already submerged" << std::endl;
        }
    }

    void surface()
    {
        if (m_submerged)
        {
            m_submerged = false;
            std::cout << "Your submarine has surfaced" << std::endl;
        }
        else
        {
            std::cout << "Your submarine is already on the surface" << std::endl;
        }
    }

    void dive()
    {
        if (m_submerged)
        {
            if (m_depth + 50 <= m_max_depth)
            {
                m_depth += 50;
                std::cout << "Your submarine has dived deeper" << std::endl;
            }
            else
            {
                m_depth = m_max_depth;
                std::cout << "Your submarine has reached maximum depth" << std::endl;
            }
        }
        else
        {
            std::cout << "Your submarine needs to be submerged to dive" << std::endl;
        }
    }

    void surface_fast()
    {
        if (m_submerged)
        {
            m_depth = 0;
            std::cout << "Your submarine has surfaced rapidly" << std::endl;
        }
        else
        {
            std::cout << "Your submarine needs to be submerged to surface rapidly" << std::endl;
        }
    }

    void emergency_stop()
    {
        if (m_submerged)
        {
            std::cout << "Your submarine has made an emergency stop" << std::endl;
        }
        else
        {
            std::cout << "Your submarine needs to be submerged to make an emergency stop" << std::endl;
        }
    }

    void shutdown()
    {
        std::cout << "Shutting down the submarine system. Thank you for diving!" << std::endl;
        still_diving = false;
    }

    virtual void display_title() = 0;

    virtual void display_options() = 0;

    std::string name() { return m_name; }

    int depth() { return m_depth; }

    int max_depth() { return m_max_depth; }

    void name(std::string name) { m_name = name; }

    void depth(int depth) { m_depth = depth; }
};

// Derived class 1
class YellowSubmarine : public Submarine
{
public:
    YellowSubmarine(std::string name, int depth, int max_depth) : Submarine(name, depth, max_depth) {}

    void sing()
    {
        std::cout << "We all live in a yellow submarine, yellow submarine..." << std::endl;
    }

    void display_title() override
    {
        std::cout << "+----------------------------------+" << std::endl;
        std::cout << "|        The Yellow Submarine       |" << std::endl;
        std::cout << "+----------------------------------+" << std::endl;
    }

    void display_options() override
    {
        char choice;
        std::cout << "(S)ubmerge | (D)ive | (F)ast Surface | E(m)ergency Stop | (C)hange Name | E(x)it >> ";
        std::cin >> choice;

        switch (choice)
        {
        case 's':
            submerge();
            break;
        case 'd':
            dive();
            break;
        case 'f':
            surface_fast();
            break;
        case 'm':
            emergency_stop();
            break;
        case 'c':
            std::cout << "Enter new name: ";
            std::cin >> m_name;
            break;
        case 'x':
            shutdown();
            break;
        default:
            std::cout << "Invalid choice!" << std::endl;
        }
    }
};

// Derived class 2
class NuclearSubmarine : public Submarine
{
public:
    NuclearSubmarine(std::string name, int depth, int max_depth) : Submarine(name, depth, max_depth) {}

    void launch_missile()
    {
        std::cout << "Missile launched!" << std::endl;
    }

    void display_title() override
    {
        std::cout << "+----------------------------------+" << std::endl;
        std::cout << "|        The Nuclear Submarine      |" << std::endl;
        std::cout << "+----------------------------------+" << std::endl;
    }

    void display_options() override
    {
        char choice;
        std::cout << "(S)ubmerge | (D)ive | (F)ast Surface | E(m)ergency Stop | (L)aunch Missile | E(x)it >> ";
        std::cin >> choice;

        switch (choice)
        {
        case 's':
            submerge();
            break;
        case 'd':
            dive();
            break;
        case 'f':
            surface_fast();
            break;
        case 'm':
            emergency_stop();
            break;
        case 'l':
            launch_missile();
            break;
        case 'x':
            shutdown();
            break;
        default:
            std::cout << "Invalid choice!" << std::endl;
        }
    }
};

int main()
{
    std::string tempname;
    int tempdepth;

    std::cout << "Enter name for Yellow Submarine: ";
    std::cin >> tempname;
    std::cout << "Enter max depth for Yellow Submarine: ";
    std::cin >> tempdepth;

    YellowSubmarine myYellowSubmarine(tempname, 0, tempdepth);

    while (myYellowSubmarine.still_diving)
    {
        myYellowSubmarine.display_title();
        myYellowSubmarine.display_options();
    }

    std::cout << "Enter name for Nuclear Submarine: ";
    std::cin >> tempname;
    std::cout << "Enter max depth for Nuclear Submarine: ";
    std::cin >> tempdepth;

    NuclearSubmarine myNuclearSubmarine(tempname, 0, tempdepth);

    while (myNuclearSubmarine.still_diving)
    {
        myNuclearSubmarine.display_title();
        myNuclearSubmarine.display_options();
    }

    return 0;
}
