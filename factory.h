#include <iostream>
#include <memory>
class Product
{
public:
    virtual ~Product() {}
    virtual void process() = 0;
};

class ProductA : public Product
{
public:
    void process() override
    {
        std::cout << "Processing ProductA" << std::endl;
    }
};

class ProductB : public Product
{
public:
    void process() override
    {
        std::cout << "Processing ProductB" << std::endl;
    }
};

class ProductC : public Product
{
public:
    void process() override
    {
        std::cout << "Processing ProductC" << std::endl;
    }
};

class ProcessingStrategy
{
public:
    virtual ~ProcessingStrategy() {}
    virtual void execute() = 0;
};

class HeatingStrategy : public ProcessingStrategy
{
public:
    void execute() override
    {
        std::cout << "Heating the product" << std::endl;
    }
};

class CoolingStrategy : public ProcessingStrategy
{
public:
    void execute() override
    {
        std::cout << "Cooling the product" << std::endl;
    }
};

class MixingStrategy : public ProcessingStrategy
{
public:
    void execute() override
    {
        std::cout << "Mixing the product" << std::endl;
    }
};
class StrategyFactory
{
public:
    static std::shared_ptr<ProcessingStrategy> createStrategy(const std::string &type)
    {
        if (type == "Heating")
            return std::make_shared<HeatingStrategy>();
        else if (type == "Cooling")
            return std::make_shared<CoolingStrategy>();
        else if (type == "Mixing")
            return std::make_shared<MixingStrategy>();
        else
            return nullptr;
    }
};

