#include <iostream> 
#include <iomanip> 
#include <string> 
#include <vector> 

#define DECIMAL_DIGIT 2 

struct Student { 
    int id; 
    std::string name; 
    std::vector<int> scores; 
}; 

std::vector<Student> students = { 
    {1, "Alice", {85, 92, 78, 94, 88}}, 
    {2, "Bob", {76, 81, 72, 85, 79}}, 
    {3, "Charlie", {93, 89, 84, 91, 95}}, 
    {4, "David", {65, 70, 75, 60, 80}}, 
    {5, "Eve", {54, 68, 72, 77, 65}} 
}; 

// Function to calculate average score
float calculateAverage(const Student& student) { 
    int sum = 0; 
    for (int score : student.scores) { 
        sum += score; 
    } 
    float average = static_cast<float>(sum) / student.scores.size(); 
    return average;  
} 

// Function to calculate GPA based on average score
float calculateGPA(const Student& student) { 
    float average = calculateAverage(student); 
    if (average >= 90) { 
        return 4.0; 
    } else if (average >= 80) { 
        return 3.0; 
    } else if (average >= 70) { 
        return 2.0; 
    } else if (average >= 60) { 
        return 1.0; 
    } else { 
        return 0.0; 
    } 
} 

// Function to calculate the grade based on GPA
std::string calculateGrade(const Student& student) { 
    float gpa = calculateGPA(student); 
    if (gpa == 4.0) { 
        return "A"; 
    } else if (gpa == 3.0) { 
        return "B"; 
    } else if (gpa == 2.0) { 
        return "C"; 
    } else if (gpa == 1.0) { 
        return "D"; 
    } else { 
        return "E"; 
    } 
} 

// Function to print student statistics
void printStudentStatistics(const Student& student) { 
    float average = calculateAverage(student); 
    float gpa = calculateGPA(student); 
    std::string grade = calculateGrade(student); 
    std::cout << "| " << std::setw(10) << student.id << " | " 
              << std::setw(10) << student.name << " | " 
              << std::setw(14) << average << " | " 
              << std::setw(4) << gpa << " | " 
              << std::setw(5) << grade << " |\n"; 
} 

int main() { 
    std::cout << std::fixed << std::setprecision(DECIMAL_DIGIT);  // Set decimal precision for average and GPA
    
    std::cout << "------------------------------------------------------------\n"; 
    std::cout << "| Student ID | Name       | Average Score | GPA  | Grade |\n"; 
    std::cout << "------------------------------------------------------------\n"; 
    
    // Call the function printStudentStatistics for each student
    for (const Student& student : students) { 
        printStudentStatistics(student); 
    } 
    
    std::cout << "------------------------------------------------------------\n"; 

    return 0; 
}

