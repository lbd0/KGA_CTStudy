/*
Q.���� ���ڿ�

���ڿ��� ���� ������ ���� �� ���� ũ�⸦ ���Ϸ��� �մϴ�.

�� ���� n�� m�̶��
">", "=" : n >= m
"<", "=" : n <= m
">", "!" : n > m
"<", "!" : n < m
�� ���ڿ� ineq�� eq�� �־����ϴ�. ineq�� "<"�� ">"�� �ϳ���, 
eq�� "="�� "!"�� �ϳ��Դϴ�. �׸��� �� ���� n�� m�� �־��� ��, 
n�� m�� ineq�� eq�� ���ǿ� ������ 1�� �ƴϸ� 0�� return�ϵ��� solution �Լ��� �ϼ����ּ���.
*/

#include <string>

int solution(std::string ineq, std::string eq, int n, int m) {

    if (ineq == ">" && eq == "=") return n >= m;
    else if (ineq == "<" && eq == "=") return n <= m;
    else if (ineq == ">" && eq == "!") return n > m;
    else if (ineq == "<" && eq == "!") return n < m;
}