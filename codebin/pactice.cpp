#include<iostream>
using namespace std;
class Aadithya{
    public:
        string Name = "Aadithya";
        string Email = "aadithyaanandan123@gmail.com";
        string Github_profile = "Aadithya369";
        string Hobbies [4] = {"Chess","Video games","Movies","Coding"};

    private:
        string ph_no = "9360028871";
        string address = "101,sekkumedu street,valathur,Gudiyatham taluk,vellore district,tamil nadu";

    protected:
        string projects[3] = {"Tic Tac Toe","Guess the number","Rock,Paper,Scissor"};
        string ongoing_projects[2] = {"VIT_HUB","Rubix Cube"};
};
class MyProfile : public Aadithya{
    public:
    void display(){
        cout << "Name: " << Name << "\n";
        cout << "Email: " << Email << "\n";
        cout << "Github: " << Github_profile << "\n";
        cout << "Hobbies: "; 
        for(int i = 0;i<sizeof(Hobbies)/sizeof(Hobbies[0]);i++){
            cout << Hobbies[i] <<"\n";
        };
    }
};
int main(){
    MyProfile ref;
    ref.display();
}