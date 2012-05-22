//Name: Blue Gene, Jr.
//Level: 1
//Category: �V�~�����[�V����,��邾��
//Note: ��蕶���ǂ݂ɂ���

/*
 * ��蕶���ǂ݂ɂ������C�v����ɐ擪���珇�ɓǂ�ōs����
 * �E�����Ȃ炻�̐�������񂾏ꏊ���������Ă��炻�̐�����1���炷�D0�Ȃ牽�����Ȃ��D
 * �E�A���t�@�x�b�g�Ȃ玟�̕������������Ă���C�������E�ŋN�����ω���%10�ɒu������
 * �Ƃ������������悤�ɏ����Ă���D
 * ���̒ʂ�Ɏ������邾���D
 */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>
#include <cassert>

using namespace std;

int mutate(int pos, string &code) {
    if(pos >= code.size()) return 0;

    if(isalpha(code[pos])) {
        int cnt = mutate(pos+1, code);
        code[pos] = '0' + (cnt % 10);
        return cnt + 1;
    }
    else if(isdigit(code[pos])) {
        int val = code[pos] - '0';
        if(val == 0) return 0;
        int next = pos + val;
        int cnt = 0;
        if(next >= code.size()) {
            cnt = mutate(pos+1, code);
        }
        else {
            cnt = mutate(next, code);
        }
        --code[pos];
        return cnt + 1;
    }
    else {
        assert(0);
    }
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    while(true) {
        string cmd;
        cin >> cmd;
        if(cmd == "ENDOFINPUT") break;
        
        int N;
        cin >> N;
        string code;
        cin >> code;
        cin >> cmd; // ignore "END"

        mutate(0, code);
        cout << code << endl;
    }
    return 0;
}
