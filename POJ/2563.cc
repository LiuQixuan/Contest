//Name: Demerit Points
//Level: 2
//Category: �V�~�����[�V����
//Note:

/*
 * �C�����ăV�~�����[�V�������邾���D
 * 2�N����merit point�̕t�^�́C�N�̃p���e�B�ŊǗ�����ƈ����₷���D
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cstdio>

using namespace std;

void parse(const string &date, int &year, int &month, int &day) {
    year = atoi(date.substr(0, 4).c_str());
    month = atoi(date.substr(4, 2).c_str());
    day = atoi(date.substr(6, 2).c_str());
}

void output(int year, int month, int day, int pt) {
    printf("%04d-%02d-%02d ", year, month, day);
    if(pt == 0) {
        puts("No merit or demerit points.");
    }
    else if(pt < 0) {
        printf("%d demerit point(s).\n", -pt);
    }
    else if(pt > 0) {
        printf("%d merit point(s).\n", pt);
    }
}

void sim(int year, int month, int day, int &point, int &parity) {
    if(year%2 == parity && point >= 0) {
        ++point;
        output(year, month, day, point);
    }
    else if(point < 0) {
        // demerit point��2���炷���C�����ɂ���(������0�֊ۂ߂�)�̂ǂ��炩�傫���ق���I�ԁD
        int diff = max(2, (abs(point)+1)/2);
        point += diff;

        // demerit point��1�̂Ƃ���2���炵�ăI�[�o�[����̂ŃN���b�v����D
        if(point > 0) point = 0;

        // �|�C���g��0�ɂȂ�����C���̎��_����2�N���Ƃ�merit point���t�^�����D
        if(point == 0) parity = year%2;
        output(year, month, day, point);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int year, month, day;
    int parity;
    int point = 0;
    {
        string init;
        cin >> init;
        parse(init, year, month, day);
        output(year, month, day, point);
        parity = year % 2;
        year += 2;
    }

    string date;
    int demerit;
    while(cin >> date >> demerit) {
        int y, m, d;
        parse(date, y, m, d);
        while((year < y) ||
              (year == y && ((month < m) ||
                             (month == m && day <= d)))) {
            sim(year, month, day, point, parity);
            ++year;
        }
        if(point > 0) {
            // merit point��demerit point���ł�����葊�E������D
            int delta = min((demerit+1)/2, point);
            point -= delta;
            demerit -= delta*2;
        }
        if(demerit > 0) {
            // �����ɗ�����merit point��0�ɂȂ��Ă���D
            point -= demerit;
        }
        year = y; month = m; day = d;
        output(y, m, d, point);
        parity = year%2;
        ++year;
    }

    while(point < 5) {
        sim(year, month, day, point, parity);
        ++year;
    }

    return 0;
}
