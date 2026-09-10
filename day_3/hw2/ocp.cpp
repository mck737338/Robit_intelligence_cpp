#include <iostream>

using namespace std;


class Report {      //기본 클래스
public:
    virtual void generate() = 0;
    ~Report() {}
};


class PDFReport : public Report {       //PDF 보고서 클래스
public:
    virtual void generate(){        //가상함수 generate 재정의
        cout << "Generating PDF report..." << endl;
    }
};


class HTMLReport : public Report {      // HTML 보고서 클래스
public:
    virtual void generate(){        //가상함수 generate 재정의
        cout << "Generating HTML report..." << endl;
    }
};


class XMLReport : public Report {       // XML 보고서 클래스
public:
    virtual void generate(){        //가상함수 generate 재정의
        cout << "Generating XML report..." << endl;
    }
};


int main() {
    Report* pdfReport = new PDFReport();    //pdf 생성
    pdfReport->generate();

    Report* htmlReport = new HTMLReport();  //html 생성
    htmlReport->generate();

    Report* xmlReport = new XMLReport();    //xml 생성
    xmlReport->generate();

}