#include "iostream"
#include "fstream"
#include "sstream"
#include "implementation.h"
using namespace std;

namespace Records {
    Implement::Implement() {
        adminPassword = password;
    }

    string Implement::setPassword() {
        string aPassword=adminPassword;
        return aPassword;
    }
    int Implement::ticket()  {
        string fTicketNO;
        ifstream fileTicket("ticket.txt");
        if(fileTicket.is_open()){
            while(getline(fileTicket,fTicketNO)){
                fTicketNO += " ";
                for(auto &num :fTicketNO){
                    if( num == ' '){
                        stringstream tt;
                        tt << fTicketNO;
                        tt >> luckyTicket[luckyNoIndex];
                        luckyNoIndex++;
                    }else{
                        string ch(1,num);
                        fTicketNO += ch;
                    }
                }
            }
        }else{
            return 0;
        }
        return luckyNoIndex;
    }

    int Implement::fileTicket(int ticket_no) {
        int no=ticket();
        ofstream file_ticket;
        file_ticket.open("ticket.txt",ios::app);
        if (no==0){
            file_ticket<< ticket_no << endl;
            return 0;
        }else {
            for (int i = 0; i < no; i++) {
                if (ticket_no == luckyTicket[i]) {
                    return -1;
                }
            }
            file_ticket << ticket_no<<endl;
            return 0;
        }
        file_ticket.close();
    }

    int Implement::checkUserT(int ticket_no) {
        int result = fileTicket(ticket_no);
        return result;
    }

    void Implement::customerDataFile(int ticket_no, std::string name, std::string phNo, std::string address) {
        ofstream dataRecord;
        dataRecord.open("luckytickerrecordsfile.txt",ios::app);
        dataRecord<<"Ticker_no:"<<ticket_no<<" "<<"Name:"<<name<<" "<<"Ph_no:"<<phNo<<" "<<"Address:"<<address<<endl;
        dataRecord.close();
    }

    void Implement::availableTicket() {
        int n=1;
        int indexT=ticket();
        for (int i = 1 ; i<= 900 ;i++){
            ++startOfLuckyNo;
            stringstream ss;
            ss << startOfLuckyNo;
            ss >> availableT[i];
            for ( int j =0  ; j <indexT; j++){
                if ( startOfLuckyNo == luckyTicket[j]){
                    availableT[i]="***";
                }
            }
            cout << availableT[i] <<" ";
            if (  i == n*30){
                cout << endl;
                n++;
            }
        }
        startOfLuckyNo=99;
        cout<< endl;
    }

    void Implement::lotteryCustomerData() {
        int count=0;
        string data;
        string readFile;
        ifstream recordData("luckytickerrecordsfile.txt");
        if (recordData.is_open()) {
            while (getline(recordData, readFile)) {
                readFile += " ";
                for (auto &ch: readFile) {
                    if (ch == ' ') {
                        if (count == 0){
                            stringstream ss;
                            ss << data;
                            ss >> luckyTicket[luckyIndex];
                            luckyIndex++;
                            count++;
                        }
                        else if (count == 1) {
                            customerName[nameIndex] = data;
                            nameIndex++;
                            count++;
                        } else if (count == 2) {
                            customerPh_no[phNoIndex] = data;
                            phNoIndex++;
                            count++;
                        } else if (count == 3) {
                            customerAddress[addressIndex] = data;
                            addressIndex++;
                            count = 0;
                        }
                    } else if (ch == ':') {
                        data = "";
                    } else {
                        string cha(1, ch);
                        data += cha;
                    }
                }
            }
        }else{
            cout << "THERE IS NO DATA IN THE FILE!\n"<<endl;
        }
        displayAllCustomerData();
        nameIndex=0;
        luckyIndex=0;
        phNoIndex=0;
        addressIndex=0;
    }

    void Implement::displayAllCustomerData() {
        for (int i =0 ; i < nameIndex ; i++){
            cout << "Lucky number : "<< luckyTicket[i]<<endl;
            cout << "Name         : "<< customerName[i]<<endl;
            cout << "Phone Number : "<< customerPh_no[i]<<endl;
            cout << "Address      : "<< customerAddress[i]<<endl;
            cout << "-----------------------------"<<endl;
        }
    }
}