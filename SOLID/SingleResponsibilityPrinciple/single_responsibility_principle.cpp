
//The Single Responsibility Principle (SRP)
//The idea behind the SRP is that every class, module, or function in a program should have one responsibility/purpose in a program. 
//As a commonly used definition, "every class should have only one reason to change".



int main()
{

}



public class Student {

     public void registerStudent() {
         // some logic
     }

     public void calculate_Student_Results() {
         // some logic
     }

     public void sendEmail() {
         // some logic
     }

}
//The class above violates the single responsibility principle. Why?

//This Student class has three responsibilities – registering students, calculating their results, and sending out emails to students.

//The code above will work perfectly but will lead to some challenges. We cannot make this code reusable for other classes or objects. The class has a whole lot of logic interconnected that we would have a hard time fixing errors. And as the codebase grows, so does the logic, making it even harder to understand what is going on.

//Imagine a new developer joining a team with this sort of logic with a codebase of about two thousand lines of code all congested into one class.

//Now let's fix this!

public class StudentRegister {
    public void registerStudent() {
        // some logic
    }
}
public class StudentResult {
    public void calculate_Student_Result() {
        // some logic
    }
}
public class StudentEmails {
    public void sendEmail() {
        // some logic
    }
}


