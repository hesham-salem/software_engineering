
//https://www.tomdalling.com/blog/software-design/solid-class-design-the-open-closed-principle/
//You should be able to extend a classes behavior, without modifying it.

/* the concept is mean that the inteface class(base class) able to acept(extend) new version of modified class without any change of logic of 
intface class this applyed by polymorephism(dependency injection) finally( don't think of this as we can add more functions to norml class without modification
because this done by single rospensiblity 
//XMLConverter */
class XMLConverter {
public:
    String convertDocumentToXML(Document doc);
}


//BinaryConverter
class BinaryConverter {
public:
    Data convertDocumentToBinary(Document doc);
}


//DocumentExporter

enum ConverterType {
    XMLConverterType,
    BinaryConverterType
};

class DocumentExporter {
private:
    URL _runSaveDialog();
    void _showSuccessDialog;
    ConverterType _converterType;
public:
    void setConverterType(ConverterType converterType);
    void exportDocument(Document doc);
};

void DocumentExporter::exportDocument(Document doc)
{
    URL fileURL = _runSaveDialog();

    switch(_converterType){
        case XMLConverterType:{
            XMLConverter xmlConverter;
            String xmlFileContent = xmlConverter.convertDocumentToXML(doc);
            xmlFileContent.writeToURL(fileURL);
            break;
        }

        case BinaryConverterType:{
            BinaryConverter binaryConverter;
            Data binaryFileContent = binaryConverter.convertDocumentToBinary(doc);
            binaryFileContent.writeToURL(fileURL);
            break;
        }

        default:
            LogError("Unrecognised converter type");
            return;
    }

    _showSuccessDialog();
}

/*
The DocumentExporter class is not closed to change. Every time a new export format must be supported, the DocumentExporter class must be modified.
"𝙀𝙣𝙪𝙢𝙨 𝙖𝙣𝙙 𝙨𝙬𝙞𝙩𝙘𝙝 𝙨𝙩𝙖𝙩𝙚𝙢𝙚𝙣𝙩𝙨" are strong indicators that a class is not closed to changes.


he way to close DocumentExporter to changes, in this case, is to make an abstract base class for all the converters. Then, the converter can be supplied
to DocumentExporter via a technique called dependency injection. The solution is as follows:
*/

//worked example


#include <iostream>
#include <string.h>
using namespace std;

using Data = string;
using Document = string;
using URL = string;
// XMLConverter

class Converter
{
public:
    virtual Data convertDocumentToData(Document doc) = 0;
};

// XMLConverter

class XMLConverter : public Converter
{
public:
    Data convertDocumentToData(Document doc);
};

Data XMLConverter::convertDocumentToData(Document doc)
{
    cout << "from  XMLConverter " << endl;
    cout << doc << endl;
}

// BinaryConverter

class BinaryConverter : public Converter
{
public:
    Data convertDocumentToData(Document doc);
};

Data BinaryConverter::convertDocumentToData(Document doc)
{
    cout << "from  BinaryConverter " << endl;
    cout << doc << endl;
}

// DocumentExporter

class DocumentExporter
{
private:
    // URL _runSaveDialog();
    void _showSuccessDialog();
    Converter *_converter;

public:
    void setConverter(Converter *converter); // Here is the dependency injection function
    void exportDocument(Document doc);
};
void DocumentExporter::_showSuccessDialog()
{
    cout << "done" << endl;
}
void DocumentExporter::setConverter(Converter *_converter)
{
    this->_converter = _converter;
}
void DocumentExporter::exportDocument(Document doc)
{
    //  URL fileURL = _runSaveDialog();
    Data fileContent = _converter->convertDocumentToData(doc);
    //  fileContent.writeToURL(fileURL);
    _showSuccessDialog();
}
// add this
class txtConverter : public Converter
{
public:
    Data convertDocumentToData(Document doc);
};
Data txtConverter::convertDocumentToData(Document doc)
{
    cout << "from  txt " << endl;
    cout << doc << endl;
}

int main()
{
    // using polymorephism
    Document doc("بسم الله ");
    // example
    DocumentExporter myExporter;
    txtConverter xml_object;
    myExporter.setConverter(&xml_object);
    myExporter.exportDocument(doc);
}
