#include<iostream>
#include<string>

using namespace std;

class Message{
    protected:
        string text;

    public:
    Message(string txt = "") : text(txt) {}

        void set_text(string text) {
            this -> text = text;
        }
        string get_text(){ 
            return text; 
        }

        
        virtual string toString(){
            return text;
        }

};

class SMS: public Message{
    string recipientContactNo;
    public:
        SMS(string txt = "", string contactNo = "") : Message(txt), recipientContactNo(contactNo) {}

        void set_number(int num){
            recipientContactNo = num;
        }
        string get_number(){
            return recipientContactNo;
        }
        string toString() override {
            return "Recipient: " + recipientContactNo + " | Message: " + text;
        }

};

class Email : public Message{
    string sender, receiver, subject;

    public:
    Email(string txt = "", string sndr = "", string rcvr = "", string subj = "") : Message(txt), sender(sndr), receiver(rcvr), subject(subj) {}

    void setSender(string sndr) { 
        sender = sndr; 
    }
    void setReceiver(string rcvr) { 
        receiver = rcvr; 
    }
    void setSubject(string subj) { 
        subject = subj; 
    }
    string getSender() { 
        return sender; 
    }
    string getReceiver() { 
        return receiver; 
    }
    string getSubject() { 
        return subject; 
    }
    string toString() override {
        return "subject: " + subject + "\nsender: " + sender + "\nreciever: " + receiver + "\nMessage: " + text;
    }
};

bool ContainsKeyword(Message& messageObject, const string& keyword){
    return messageObject.toString().find(keyword);
}

string encode_message(const string& message) {
    string encoded_message = message;
    for (char& ch : encoded_message) {
        if (isalpha(ch)) {
            if (ch == 'Z') ch = 'A';
            else if (ch == 'z') ch = 'a';
            else ch++;
        }
    }
    return encoded_message;
}


int main(){
    SMS sms("Hello, how are you?", "1234567890");
    cout << "SMS: " << sms.toString() << endl;

    Email email("Meeting at 5 PM", "ahmed@karachi.com", "saim@lahori.com", "Meeting Reminder");
    cout << "Email: " << email.toString() << endl;
    string keyword = "Meeting";

    if (ContainsKeyword(email, keyword)){
        cout << "keyword found" << endl;
    }
    else cout << "keyword not found" << endl;

    string encoded = "This is Java";
    encoded = encode_message(encoded);
    cout << "Encoded Message: " << encoded << endl;
}
