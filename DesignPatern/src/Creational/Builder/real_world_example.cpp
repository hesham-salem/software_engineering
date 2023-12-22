#include <iostream>
#include <string>
#include <vector>
#include <memory>

// "Product"
class Document {
public:
    void addContent(const std::string& content) {
        contents.push_back(content);
    }

    void show() const {
        for (const auto& line : contents) {
            std::cout << line << std::endl;
        }
    }

private:
    std::vector<std::string> contents;
};

// "Abstract Builder"
class DocumentBuilder {
public:
    virtual void buildTitle(const std::string& title) = 0;
    virtual void buildParagraph(const std::string& paragraph) = 0;
    virtual std::unique_ptr<Document> getDocument() = 0;
    virtual ~DocumentBuilder() {}
};

// "Concrete Builder for HTML"
class HTMLDocumentBuilder : public DocumentBuilder {
private:
    std::unique_ptr<Document> document;

public:
    HTMLDocumentBuilder() : document(std::make_unique<Document>()) {}

    void buildTitle(const std::string& title) override {
        document->addContent("<h1>" + title + "</h1>");
    }

    void buildParagraph(const std::string& paragraph) override {
        document->addContent("<p>" + paragraph + "</p>");
    }

    std::unique_ptr<Document> getDocument() override {
        return std::move(document);
    }
};

// "Concrete Builder for Plain Text"
class PlainTextDocumentBuilder : public DocumentBuilder {
private:
    std::unique_ptr<Document> document;

public:
    PlainTextDocumentBuilder() : document(std::make_unique<Document>()) {}

    void buildTitle(const std::string& title) override {
        document->addContent(title + "\n" + std::string(title.length(), '='));
    }

    void buildParagraph(const std::string& paragraph) override {
        document->addContent(paragraph);
    }

    std::unique_ptr<Document> getDocument() override {
        return std::move(document);
    }
};

// "Director"
class DocumentDirector {
public:
    void constructTestDocument(DocumentBuilder& builder) {
        builder.buildTitle("Test Document");
        builder.buildParagraph("This is the first paragraph.");
        builder.buildParagraph("This is the second paragraph.");
    }
};

// "Client"
int main() {
    HTMLDocumentBuilder htmlBuilder;
    PlainTextDocumentBuilder plainTextBuilder;

    DocumentDirector director;

    // Construct HTML Document
    director.constructTestDocument(htmlBuilder);
    auto htmlDocument = htmlBuilder.getDocument();
    std::cout << "HTML Document:" << std::endl;
    htmlDocument->show();

    std::cout << "\n";

    // Construct Plain Text Document
    director.constructTestDocument(plainTextBuilder);
    auto plainTextDocument = plainTextBuilder.getDocument();
    std::cout << "Plain Text Document:" << std::endl;
    plainTextDocument->show();

    return 0;
}
/* output
HTML Document:
<h1>Test Document</h1>
<p>This is the first paragraph.</p>
<p>This is the second paragraph.</p>

Plain Text Document:
Test Document
=============
This is the first paragraph.
This is the second paragraph.


*/
