#ifndef HELPER_H_INCLUDED //this is where the unidentified keystrokes are defined
#define HELPER_H_INCLUDED

#include<ctime>
#include<string>
#include<sstream>
#include<fstream>


namespace Helper{
    template <class T>//to accept any generic types,

    std::string ToString(const T &); //declration of fun which will convert anything into string

    struct DateTime{ //this structure is to get the time from the running system
        DateTime(){  //creating a fun to collect all these datas
            time_t ms;
            time(&ms);//i dont know wht it is
            struct tm *info=localtime(&ms);//struct tm is a structure that is defined in 'ctime.h' and using tht we declrd a pointr
                                  // now the tm contains the details about the time and date of the DateTime structure

            D=info->tm_mday; //day
            M=info->tm_mon+1; //month
            Y=(info->tm_year)+1900; //

            h=info->tm_hour; //hour
            m=info->tm_min; //min
            s=info->tm_sec; //sec
            }
        DateTime(int D, int M, int Y, int h, int m, int s) : D(D), M(M), Y(Y), h(h), m(m), s(s) {} //this will create a instance of time
        DateTime(int D, int M, int Y) : D(D), M(M), Y(Y), h(0), m(0), s(0) {}

        DateTime Now() const{  //only reads the class, not chnge
        return DateTime();
        }
        int D,M,Y,h,m,s;

        std::string GetDateString() const{
        return std::string(D < 10 ? "0" : "") + ToString(D)+
               std::string(M < 10 ? ".0" : "." )+ ToString(M) + "."+
               ToString(Y);
        }
        std::string GetTimeString(const std::string &sep = ":")const { //using sep we setted the default seperator is a colon
        return std::string(h < 10 ? "0" : "") + ToString(h)+ sep +
               std::string(m < 10 ? "0" : "") + ToString(m) + sep +
               std::string(s < 10 ? sep : "") + ToString(s);
        }
        std::string GetDateTimeString(const std::string &sep = ":")const{
        return GetDateString()+" " +GetTimeString(sep);
        }
    };

    template <class T>
    std::string ToString(const T &e){
    std::ostringstream s;
    s<<e;
    return s.str();
    }

    void WriteAppLog(const std::string &s){
    std::ofstream file("Applog.txt",std::ios::app);
    file<<"["<<Helper::DateTime().GetDateTimeString()<< "]" <<
    "\n"<<s<<std::endl<<"\n";
    file.close();
    }



}
#endif // HELPER_H_INCLUDED
