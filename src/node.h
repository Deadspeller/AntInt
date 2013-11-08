class node{

public:
    node(int, int, int, int);
    int getxPos();
    int getyPos();
    int getDistance();
    int getPriority();
    void updatePriority(const int, const int);
    void updateDistance();
    const int estimateDIstance(const int, const int);


};
