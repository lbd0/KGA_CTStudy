/*
Q. �����

���� number�� n, m�� �־����ϴ�. 
number�� n�� ����̸鼭 m�� ����̸� 1�� �ƴ϶�� 
0�� return�ϵ��� solution �Լ��� �ϼ����ּ���.
*/

int solution(int number, int n, int m) {
	return (number % n == 0) ? (number % m == 0) ? 1 : 0 : 0;
}