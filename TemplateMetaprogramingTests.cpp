#include <iostream>
#include <queue>
#include <string>

template <typename Predicate>
class TestPredicate{
    Predicate t;
public:
    TestPredicate(Predicate functor):t(functor){}
    template<typename O>
    bool operator()(O o){return t(o);}
};

template <typename T>
void test(T t){t();}


int main()
{
    TestPredicate<bool(*)(const std::vector<std::string>&)> t([](const std::vector<std::string>& value)->bool
    {
        std::cout << "Template called with value: " << value[0] << "!!" << std::endl;
        return true;
    });
    std::vector<std::string> vecStr{"### Vec Index 0 ###", "### Vec Index 1 ###"};
    
    std::cout << t(vecStr) << std::endl;
    
    test(
            []()->void
            {
                std::cout << "test template function given a lambda" << std::endl;
                return;
            }
        );
    
    return 0;
}
