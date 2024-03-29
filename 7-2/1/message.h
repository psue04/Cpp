#include <map>
#include <vector>

class MessageBook {
public:
    MessageBook();
    ~MessageBook();

    void AddMessage(int number, const std::string& message);
    void DeleteMessage(int number);
    std::vector<int> GetNumbers();
    const std::string& GetMessage(int number);

private:
    std::map<int, std::string> message;
    //static const std::string empty_string;
};