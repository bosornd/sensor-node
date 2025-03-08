#ifndef DATA_HPP
#define DATA_HPP

class Data {
public:
    Data(int data = 0);
    Data(const Data& other);
    Data& operator=(int data);
    Data& operator=(const Data& other);
    operator int() const;

private:
    int data;
};

#endif // DATA_HPP