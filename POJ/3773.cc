//Name: String-Matching Automata
//Level: 4
//Category: ������,�I�[�g�}�g��
//Note:

/*
 * �m�[�h N �̑J�ڂ͂������̃m�[�h�ɂ͈ˑ����Ȃ�����C�擪���珇�ɑJ�ڂ����߂Ă������Ƃ��ł���D
 * �܂��C����m�[�h�Ŏ��s�����Ƃ��ɖ߂�ꏊ�́C���̃m�[�h�܂ł̕������ suffix �̂����C
 * �󗝂�����������̐擪�ƃ}�b�`����C�ł����� suffix �̒����Ō��܂�D
 * �v����ɂ���͐擪�ȊO�̏ꏊ����m�[�h N �܂ő��������񂪉������ڂ܂Ŏ󗝂���Ă��邩�C�Ƃ������Ƃɓ������̂�
 * 1�����x��ŃI�[�g�}�g�������ǂ��Ă����|�C���^ shadow �����C�m�[�h N �Ŏ��s�����Ƃ��� shadow ����̑J�ڂ�
 * �g���悤�ɂ���΂悢�D
 *
 * Sample Input ���ɂ����
 * ababaca �ɑ΂��� shadow ��
 * babaca ���󗝂��悤�Ǝ��݂�D
 * ���̂Ƃ� shadow �ɕK�v�ȃm�[�h�͑S�đJ�ڂ��������Ă���C���� shadow �̂���m�[�h��
 * ababaca �ȊO�̕�������ő���󗝂����Ƃ��̃m�[�h�ɂȂ��Ă���D
 *
 * �I�[�_�[�� O(N)�D
 */ 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(true) {
        string line;
        getline(cin, line);
        if(line == "0") break;
        const int N = line.size();
        vector<vector<int> > automaton(N+1, vector<int>(26, 0));
        int shadow = 0;
        for(int i = 0; i < N+1; ++i) {
            // shadow transient
            for(int ch = 0; ch < 26; ++ch) {
                automaton[i][ch] = automaton[shadow][ch];
            }
            if(i < N) {
                shadow = automaton[shadow][line[i]-'a'];
                automaton[i][line[i]-'a'] = i+1;
            }
        }
        for(int i = 0; i <= N; ++i) {
            cout << i;
            for(int ch = 0; ch < 26; ++ch) {
                cout << ' ' << automaton[i][ch];
            }
            cout << endl;
        }
    }
    return 0;
}
