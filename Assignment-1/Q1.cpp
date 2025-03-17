#include <iostream>
#include <string>
using namespace std;

class Student;

class Skill {
    int skill_id;
    string name;
    string description;
public:
    Skill() : skill_id(0), name(""), description("") {}
    
    Skill(int id, string name, string description) 
         : skill_id(id), name(name), description(description) {}
    void show_skill_details(){
        cout << "Skill: " << name << "\nDescription: " << description << endl;
    }
    void update_skill_detail(string description){
        this->description = description;
    }
    string getName() const{ 
        return name; 
    }
};


class Sport {
    int sportID;
    string name;
    string description;
    Skill requiredSkills[10];
    int numSkills;
public:
    Sport(int id, string name, string description): sportID(id), name(name), description(description), numSkills(0) {}
    
    string getName() const {
        return name;
    }
    void addSkill(const Skill &s) {
        if (numSkills < 10) {
            requiredSkills[numSkills++] = s;
            cout << "Skill " << s.getName() << " added to " << name << "\n";
        } else {
            cout << "Cannot add more skills to " << name << "\n";
        }
    }
    void removeSkill(const Skill &s) {
        bool found = false;
        for (int i = 0; i < numSkills; i++) {
            if (requiredSkills[i].getName() == s.getName()) {
                for (int j = i; j < numSkills - 1; j++)
                    requiredSkills[j] = requiredSkills[j + 1];
                numSkills--;
                cout << "Skill " << s.getName() << " removed from " << name << "\n";
                found = true;
                break;
            }
        }
        if (!found)
            cout << "Skill " << s.getName() << " not found in " << name << "\n";
    }
    void display() {
        cout << "Sport: " << name << "\nDescription: " << description << "\n";
    }
};


class Mentor {
    int mentorID;
    string name;
    int max_learners;
    int num_expertise;
    string* sports_expertise;
    Student** assigned_learners;
    int current_learners;
public:
    Mentor(int id, string name, int max_learners, int num_expertise, string expertise[]){
        mentorID = id;
        this->name = name;
        this->max_learners = max_learners;
        this->num_expertise = num_expertise;
        current_learners = 0;
        sports_expertise = new string[num_expertise];

        for (int i=0; i<num_expertise; i++){
            sports_expertise[i] = expertise[i];
        }

        assigned_learners = new Student*[max_learners];
    }
    string get_name(){
        return name;
    }
    void assign_learner(Student* s){

        if (current_learners < max_learners){
            assigned_learners[current_learners++] = s;
            cout << "Student assigned successfully!\n";
        } 
        else{
            cout << "Mentor has reached the maximum learner capacity!\n";
        }
    }

    void view_learners();
    void remove_learner(Student* s){
        for (int i=0;i<current_learners; i++){
            if (assigned_learners[i] == s){
                for (int j=i; j<current_learners-1; j++)
                    assigned_learners[j] = assigned_learners[j+1];
                current_learners--;
                cout << "Student removed successfully!" << endl;
                return;
            }
        }
        cout << "Student not found under this mentor!" << endl;
    }
    void provide_guidance(){
        cout << "Mentor " << name << " is providing guidance." << endl;
    }
    ~Mentor(){
        delete[] sports_expertise;
        delete[] assigned_learners;
    }
};

class Student {
    int studentID;
    int age;
    string name;
    string* sport_interests;
    int num_interests;
    Mentor* mentor_assigned;
public:
    Student(int id, int age, string name, int num_interests, string interests[]){
        studentID = id;
        this->age = age;
        this->name = name;
        this->num_interests = num_interests;
        mentor_assigned = nullptr;
        sport_interests = new string[num_interests];
        for (int i=0; i<num_interests; i++){
            sport_interests[i] = interests[i];
        }
    }

    string getName() const{
        return name;
    }

    void register_for_mentorship(Mentor* m){
        if (!mentor_assigned){
            mentor_assigned = m;
            m->assign_learner(this);
        } 
        else{
            cout << "Student already has a mentor assigned."<< endl;
        }
    }


    void view_mentor_details(){
        if (mentor_assigned){
            cout << "Student " << name << " is assigned to mentor " << mentor_assigned->get_name() << endl;
        } 
        else{
            cout << "No mentor assigned." << endl;
        }
    }


    void update_sports_interest(const Sport &sport){
        if (num_interests>0){
            sport_interests[0] = sport.getName();
            cout << "Updated first interest to " << sport.getName() << " for student " << name << endl;
        }
    }

    void select_mentor(Mentor* m){
        register_for_mentorship(m);
    }
    ~Student(){
        delete[] sport_interests;
    }
};


void Mentor::view_learners(){

    cout << "Mentor " << name << " has the following learners:" << endl;

    for (int i=0; i<current_learners; i++){
        cout << "- " << assigned_learners[i]->getName() << endl;
    }
}

int main() {
    cout << "Question # 1 24k-0997 Saad Tauseef \n" << endl;
    string mentor_expertise[2] = {"basket ball","volley ball"};
    string student_interests[2] = {"Soccer","foot ball"};

    Mentor* mentor1 = new Mentor(1, "Ahmed", 3, 2, mentor_expertise);
    
    Student* student1 = new Student(101, 20, "Ali", 2, student_interests);
    
    student1->select_mentor(mentor1);
    student1->view_mentor_details();
    mentor1->view_learners();
    mentor1->provide_guidance();
    mentor1->remove_learner(student1);
    
    Sport sport1(201, "basket ball", "dribble or get lost");
    sport1.display();
    
    student1->update_sports_interest(sport1);
    
    Skill skill1(301, "dribble", "bouncing ball onto the ground.");
    Skill skill2(302, "throw", "Aim at the basket and throw the ball.");
    
    skill1.show_skill_details();
    skill2.show_skill_details();
    
    sport1.addSkill(skill1);
    sport1.addSkill(skill2);
    sport1.removeSkill(skill1);
    sport1.removeSkill(skill1); 
    
    delete mentor1;
    delete student1;
}
