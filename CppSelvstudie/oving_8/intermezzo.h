class Dummy{
    public:
    int *num;
    Dummy(){
        num = new int{0};
    }
   Dummy(const Dummy &dummy);
    ~Dummy(){
        delete num;
    }
    //Dummy Dummy::operator=(Dummy &dummy);
};

void dummyTest();