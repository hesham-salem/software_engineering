
//The Single Responsibility Principle (SRP)
//The idea behind the SRP is that every class, module, or function in a program should have one responsibility/purpose in a program. 
//As a commonly used definition, "every class should have only one reason to change".



/*
Consider a class called XMLExporter. XMLExporter takes a Document object,
and exports it into a different file format for another application.



class Exporter {
private:
    URL _runSaveDialog();
    String _exportDocumentToXML(Document doc);
    void _showSuccessDialog();
public:
    void exportDocument(Document doc);
};

void Exporter::exportDocument(Document doc)
{
    String xmlFileContent = _exportDocumentToXML(doc);
    URL fileURL = _runSaveDialog();
    xmlFileContent.writeToURL(fileURL);
    _showSuccessDialog();
}


There are at least two reasons for change (a.k.a. responsibilities) in the XMLExporter class.
The class needs to be modified if the GUI changes — for example, if an options dialog is added.
Also, the class needs to be modified if the XML format changes, or the Document needs to be exported differently.


// XMLConverter
class XMLConverter {
public:
    String convertDocumentToXML(Document doc);
}

//  XMLExporter

class Exporter {
private:
    URL _runSaveDialog();
    void _showSuccessDialog();
public:
    void exportDocument(Document doc);
};

void Exporter::exportDocument(Document doc)
{
    XMLConverter converter;
    String xmlFileContent = converter.convertDocumentToXML(doc);
    URL fileURL = _runSaveDialog();
    xmlFileContent.writeToURL(fileURL);
    _showSuccessDialog();
}

*/

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


