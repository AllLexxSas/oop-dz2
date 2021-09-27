#ifndef TASK1_H
#define TASK1_H


#include <iostream>
#include <vector>



class Person
{
protected:

private:
    static int items;
    int age;
    const char *name;
    int weight;
    const char *gender;


public:
    Person() = default;
    Person (int age, const char *name, int weight, const char *gender):
        age(age) , name(name), weight(weight), gender(gender)
    {
        items++;
    }
    ~Person()
    {
        items--;
        std::cout << "student " << name << " expelled" << std::endl;
    }
    void set_name(char *name_student)
    {
        name = name_student;
    }
    const char* get_name()
    {
        return name;
    }
    int get_age()
    {
        return age;
    }
    int get_weight()
    {
        return weight;
    }
    const char* get_gender()
    {
        return gender;
    }

    //возвращает количество студентов
    static int get_number_copies_class()
    {
        return items;
    }
};
int Person::items = 0;

class Student: public Person
{
private:
    size_t year_study;
public:
    Student(int age, const char *name, int weight, const char *gender,size_t year_study):
        Person (age, name, weight, gender), year_study(year_study){}

    //перевести студента на следующий курс
    void transfer_next_course()
    {
        if (year_study != 0)
            year_study++;
        else
            std::cout << "error!" << std::endl;
    }

    //назначить год обучения студента
    void set_year_study(size_t year_study)
    {
        this->year_study = year_study;
    }

    void print_student ()
    {
        std::cout << "Name - " << this->get_name() << std::endl;
        std::cout << "Age - " << this ->get_age() << std::endl;
        std::cout << "Weight - " << this->get_weight() << std::endl;
        std::cout << "Gender - " << this->get_gender() << std::endl;
        std::cout << "Year dtudy - " << this->year_study << std::endl;

    }
//поиск студента по имени и вывод информации
    static bool info_student(std::vector<Student *> students, const char* name_student)
    {
        for (auto item :students)
        {
            if(item->get_name() == name_student){
                item->print_student();
                return true;
            }
        }
        std::cout << "student not found\n";
        return false;
    }

};

int task1()
{
    std::vector<Student*> student;

    student.push_back( new Student(44,"Anna",45, "female", 2));
    student.push_back( new Student(23,"Vasiliy",120, "male", 3));
    student.push_back( new Student(18,"Zilfiya",67, "female", 1));
    student.push_back( new Student(31,"Alex",78, "male", 4));

    puts("displaying information about the student");
    Student::info_student(student,"Vasiliy");
    std::cout << std::endl;

    puts("student name change");
    student[1]->set_name(const_cast<char*>("Boris"));
    std::cout << std::endl;

    puts("displaying information about a student by the old name");
    Student::info_student(student,"Vasiliy");
    std::cout << std::endl;

    puts("transfer of a student to the next course");
    student[1]->transfer_next_course();

    Student::info_student(student, "Boris");
    std::cout << std::endl;

    std::cout << "number of students - " << Person::get_number_copies_class() << std::endl;

    delete (student[3]);
    std::cout << "number of students - " << Person::get_number_copies_class() << std::endl;


    return 0;
}



#endif // TASK1_H
