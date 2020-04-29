//
// Created by BanMing on 4/29/2020.
//

class AccessLevels {
public:
    int getReadOnly() const { return readOnly; }

    void setReadWrite(int val) { readWrite = val; }

    int getReadWrite() const { return readWrite; }

    void setWriteOnly(int val) { writeOnly = val; }

private:
    int noAccess;
    int readOnly;
    int readWrite;
    int writeOnly;
};

void Run() {}

