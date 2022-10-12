#include <iostream>
#include<ctime>
#include<vector>
#include<string>
#define int long long
using namespace std;
vector<int> tt(4);
string days[7] = {"Понедельник","Вторник","Среда","Четверг","Пятница","Суббота","Воскресенье"};
int time_of_monday = 1665360000;
void time_to_dhms (int time){
    tt[1] = (time/3600)%24;
    tt[0] = ((time-time_of_monday)/(3600*24))%7;
    tt[2] = (time/60)%60;
    tt[3] = (time%60);
}
void out_n(int n){
    if(n<10) cout << 0;
    cout << n;
}
void out_time (int time){
    time_to_dhms(time);
    cout << days[tt[0]] << " ";
    for(int i = 1; i < 4; ++i){
        out_n(tt[i]);
        if(i!=3) cout << ":";
    }
}
int start_lessons[6] = {91500,101000,111500,122000,132500,142000};
string lessons [6][6] = {{"Обществознание 305","Алгебра 206", "Алгебра 206", "Литература 306", "Физика 106", "Физика 106"},{"Физика 105","История 302","Информатика ВЦ","Информатика ВЦ","Геометрия 209","Геометрия 209"},{"ОБЖ 105","Обществознание 305","Литература 307","Литература 307","Алгебра 205","Алгебра 205"},{"Инфпроект 103","Русский 203","Английский 310","Химия 301","История 302","чилл"},{"Геометрия 207","Химия 301","Физика 105","Биология 311","География 304", "Физкультура"},{"Физика 102","Физика 102","Алгебра 206","Алгебра 206","Английский 310","Английский 310"}};
void vyvesti_urok (int i, int j){
    cout << "Cледующий урок состоится в ";
    cout << days[i] << " ";
    out_n (start_lessons[j]/10000);
    cout << ":";
    out_n ((start_lessons[j]/100)%100);
    cout << ":";
    out_n(start_lessons[j]%100);
    cout << '\n';
    cout << "Этим уроком будет ";
    cout << lessons[i][j];
    cout << '\n';
}
void next_lesson (int time){
    time_to_dhms(time);
    if(tt[0] == 6){
        cout << "Cегодня воскресенье. Отдыхай)" << '\n';
        return;
    }
    int shiztime = tt[3] + tt[2]*100 + tt[1]*10000;
    if(shiztime > 142000){
        if(tt[0] == 5){
            cout << "Иди на МЦ" << '\n';
            return;
        }
        vyvesti_urok(tt[0]+1,0);
        return;
    }
    if(shiztime<91500){
        vyvesti_urok(tt[0],0);
        return;
    }
    for(int i = 0; i < 5; ++i){
        if(shiztime>= start_lessons[i] && shiztime < start_lessons[i+1]){
            vyvesti_urok(tt[0],i+1);
            return;
        }
    }
}
signed main()
{
    setlocale(LC_ALL,"Russian");
    int c = 3*3600;
    cout << "Сейчас "; out_time(time(0)+c);
    cout << '\n';

    next_lesson(time(0)+c);
}
