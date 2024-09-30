// Written by MM Clark
# pragma once
# include <string>
using namespace std;

class request
{
    private:
        string question;
        string answer;
        bool processed;

    public:
        request();
        request(string);

        void setQuestion(string);
        void setAnswer(string);
        void setProcessed(bool);

        string getQuestion();
        string getAnswer();
        bool getProcessed();
        string getProcessedAsString();

        void toString();
        bool equals(request);
};

request::request()
{
    setQuestion("NONE");
    setAnswer("NONE");
    setProcessed(true);
}
request::request(string question)
{
    setQuestion(question);
    setAnswer("NONE");
    setProcessed(false);
}
void request::setQuestion(string question)
{
    if(!question.empty())
        this->question = question;
    else
        this->question = "NONE";
}
void request::setAnswer(string answer)
{
    this->answer = answer;
}
void request::setProcessed(bool processed)
{
    this->processed = processed;
}
string request::getQuestion()
{
    return this->question;
}
string request::getAnswer()
{
    return this->answer;
}
bool request::getProcessed()
{
    return this->processed;
}
string request::getProcessedAsString()
{
    return this->processed == true ? "true" : "false";
}
void request::toString();
{
    return "Question: " + this->question + " Answer: " + this->answer + 
        "Processed: " + this->getProcessedAsString();
}
bool request::equals(request other)
{
    return this->question.compare(other.getQuestion()) == 0 && this->answer.compare(other.getQuestion()) == 0
        && this->processed == other.getProcessed();
}