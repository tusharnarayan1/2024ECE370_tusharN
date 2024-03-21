class Student {
    int id; 
public:
    
    Student(int id) : id(id) {}

  
    friend bool isValid(const Student& s);
};


bool isValid(const Student& s) {
    if (s.id > 0) return true;
    else return false;
}