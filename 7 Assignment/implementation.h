#include "iostream"

namespace Records{
    const std::string password= "Admin@123";
    class Implement{
    public:
        Implement();
        int         startOfLuckyNo=99;
        int         luckyNoIndex=0;
        int         luckyIndex=0;
        int         nameIndex=0;
        int         phNoIndex=0;
        int         addressIndex=0;
        int         luckyTicket[1000];
        std::string availableT[1000];
        std::string customerName[1000];
        std::string customerPh_no[1000];
        std::string customerAddress[1000];

        std::string setPassword();
        int         ticket();                     // fist check the ticket file, if data have return index and if not return 0
        int         fileTicket(int ticket_no);    /* open the ticket file with append mode. If return value from ticket file
        is 0, push into file. Otherwise, return data from ticket have the value check user input number with array
        data, if match return -1 , if not push the number into file and return 0 */
        int         checkUserT(int ticket_no);
        void        customerDataFile(int ticket_no,std::string name,std::string phNo,std::string address);
        //Push the data of customers in customer data file
        void        availableTicket();
        void        lotteryCustomerData();       //Pop the data of customers from customer data file
        void        displayAllCustomerData();
    private:
        std::string adminPassword;
    };
}
