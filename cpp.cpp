// Kevin Kha

#include <iostream>
#include <string>
using namespace std;

//Basic input/output (cin, cout, cerr)
void feat1(){
        int x, y, sum;
        cout << "Type the first number: " << endl;
        cin >> x;
        cout << "Type the second number: " << endl;
        cin >> y;
        sum = x + y;
        cout << "The sum is: " << sum << endl;
        cerr << "You have reached the end." << endl;
}

//Dynamic memory (new, delete, delete[])
void feat2(){
        int i, x;
        int sum = 0;
        int *y;
        int *z;

        cout << "How many numbers do you want to enter? :" << endl;
        cin >> x;
        y = new int[x];

        for (i = 0; i<x; i++){
                cout << "Enter number " << i+1 << ": " << endl;
                cin >> y[i];
        }
        cout << "You have entered the number(s): ";
        for (i = 0; i<x; i++){
                cout << y[i] << " ";
                sum += y[i];
        }
        cout << endl;
        cout << "The sum of the numbers are: " << sum << endl;
        z = &sum;

        cout << "The address where z is stored is: " << z << endl;
        cout << "The value of *z variable is: " << *z << endl;

        z = NULL;
        delete[] y;
        delete z;
}

class Student {
        private:
                string firstName;
                string lastName;

        public:
                Student(){
                        cout << "Constructor called" << endl;
                        firstName = "First";
                        lastName = "Last";
                }

                ~Student(){
                        cout << "Deconstructor called" << endl;
                }

                void setInfo(string fname, string lname){
                        firstName = fname;
                        lastName = lname;
                }

                void displayInfo(){
                        cout << "Student's first name: " << firstName << endl;
                        cout << "Student's last name: " << lastName << endl;
                }

        //Student(string fname, string lname)
};

//Constructor and deconstructor
//Encapulsation: public and private members
void feat3n4(){
        Student s1;
        s1.displayInfo();
        s1.setInfo("Kevin", "Kha");
        s1.displayInfo();

}

enum week { Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday };

//Enumeration
void feat5(){
        week today;
        today = Monday;
        cout << "Today is day " << today+1 <<" of the week." << endl;
}

//Using pointer to traverse an array of some object
void feat6(){
        const size_t s = 5;
        int arr[s];
        int *p = arr + (s-1);

        //Adding some values into the array
        for (int i=0; i<s; ++i){
		arr[i] = i+1;
        }

        //Traversing the array using a pointer
        for (int *j = arr; (p-j) >= 0; ++j){
                cout << j << "  " << *j << endl;
        }
}

//Base class
class WhiteHouse{
        public:
                void address(){
                        cout << "1600 Pennsylvania Ave NW, Washington, DC 20500" << endl;
                }
};

//Derived class
class President: public WhiteHouse{
        public:
                void name(){
                        cout << "Joseph Biden" << endl;
                }
};

//Inheritance
void feat7(){
        President current;

        //calling member of derived class
        current.name();

        //calling member of base class
        current.address();
}

class number {
        public:
                void numb(int x){
                        cout << "The x is: " << x << endl;
                }

                void numb(double x){
                        cout << "The x is: " << x << endl;
                }

                void numb(string x){
                        cout << "The x is: " << x << endl;
		}
};

//Polymorphism
void feat8(){
        number n1;

        n1.numb(5);
        n1.numb(3.14);
        n1.numb("7");
}

class Arithmetic {
        protected:
                int x, y;
        public:
                void setValues (int a, int b){
                        x = a;
                        y = b;
                }
                virtual int sum(){
                        return 0;
                }
                virtual int mult() = 0;

                void printSum(){
                        cout << this->sum() << endl;
                }
                void printMult(){
                        cout << this->mult() << endl;
                }
};

class Derived: public Arithmetic{
        public:
                int sum (void){
                        return (x+y);
                }
                int mult (void){
                        return (x*y);
                }
};

class Derived2x: public Arithmetic{
        public:
                int sum (void){
                        return ((x+y)*2);
                }
                int mult (void){
                        return (x*y*2);
                }
};

//Polymorphism with virtual function and pure virtual function
void feat9(){
        Derived norm;
        Derived2x doub;
        Arithmetic *op1 = &norm;
        Arithmetic *op2 = &doub;
        norm.setValues(5,10);
        doub.setValues(5,10);
        norm.printSum();
        norm.printMult();
        doub.printSum();
        doub.printMult();
}

extern "C"{
        int printf(const char *formar,...);
}

//C in C++ (extern "C")
void feat10(){
        printf("Testing...");
        printf("\n");
}

//String object in C++
void feat11(){
        string str;
        cout << "Enter some String: ";
        getline(cin,str);
        cout << "The String entered was: " << str << endl;

        //Some string manipulation
        cout << "The String length is: " << str.length() << endl;
        str.append("123");
        cout << "After appending, new string is: " << str << endl;

        str.erase();
        cout << "String after erasing: " << str << endl;

        if (str.empty()){
                cout << "The string is empty!" << endl;
        }

}

int main(){
        //feat1();      
        //feat2();
        //feat3n4();
        //feat5();
        //feat6();
        //feat7();
        //feat8();
        //feat9();
        //feat10();
        feat11();

        return 0;
}